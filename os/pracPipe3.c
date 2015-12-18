#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define READ 0
#define WRITE 1

int main(int argc, char *argv[])
{
     int i, p[2], pid, lineno = 1, nchars;
     char line[81];
     
     line[0] = '\0';
     if (argc != 3) {
	  fprintf(stderr, "Usage: tunnel <p1> <p2>\n");
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

	  if (dup2(p[READ], 0) < 0) {
	       fprintf(stderr, "Failed to set up the parent tunnel\n");
	       exit(3);
	  }

	  execlp(argv[2], argv[2], NULL);
	  fprintf(stderr, "Error in running %s\n", argv[2]);
     }

     exit(0);
}