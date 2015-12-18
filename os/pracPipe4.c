

#include <stdio.h>
#include <string.h>
#define READ 0
#define WRITE 1

int main(int argc, char *argv[])
{
     int i, p[2], pid, lineno = 1, nchars;
     char line[81];
     
     line[0] = '\0';
     if (argc != 2) {
	  fprintf(stderr, "Usage: tunnel <p1>\n");
	  exit(1);
     }

     if (pipe(p) != 0) {
	  fprintf(stderr, "Error in Creating Pipe\n");
	  exit(1);
     }

     if ((pid = fork()) == 0) {
	  close(p[READ]);

	  if (dup2(p[WRITE], 1) < 0) {
	       fprintf(stderr, "Failed to set up the tunnel\n");
	       exit(2);
	  }
	  execlp(argv[1], argv[1], NULL);
	  fprintf(stderr, "Error in running %s\n", argv[1]);
     } else {
	  close(p[WRITE]);
	  printf("%d: ", lineno++);
	  while ((nchars = read(p[READ], line, 80)) > 0) {
	       for (i=0; i<nchars; i++) {
		    if (line[i] != '\n') {
			 printf("%c", line[i]);
		    } else {
			 if ((nchars < 80) && (i == (nchars-1))) 
			      printf("\n");
			 else 
			      printf("\n%d: ", lineno++);
		    }
	       }
	  }
	  printf("\n");
	  close(p[READ]);

	  waitpid(pid, NULL, 0);
     }

     exit(0);
}