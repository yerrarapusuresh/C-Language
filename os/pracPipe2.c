#include <stdio.h>
#include <string.h>
#define READ 0
#define WRITE 1

int main(void)
{
     int p[2], pid;
     char line[81];
     FILE *fp;

     if (pipe(p) != 0) {
	  fprintf(stderr, "Error in Creating Pipe\n");
	  exit(1);
     }

     if ((pid = fork()) == 0) {
	  close(p[READ]);

	  if ((fp = fopen("pracPipe.c", "r")) == NULL) {
	       fprintf(stderr, "Error in reading file pipe-1.c\n");
	       exit(1);
	  }

	  while (fgets(line, 81, fp) != NULL) {
	  	sleep(1);
	       write(p[WRITE], line, 80);
	  }

	  close(p[WRITE]);
	  fclose(fp);
     } else {
	  close(p[WRITE]);
	  while (read(p[READ], line, 80) > 0) {

	       printf("Parent: %s", line);
	  }
	  close(p[READ]);

	  waitpid(pid, NULL, 0);
     }

     exit(0);
}