#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

     if ((pid = fork()) == 0) 
	{
		char buff[100];
		while(1)
		{
			read(p[READ],buff,100);
			printf("%s",buff);
		}
	}

else{


	char final[50];
	int i ;
	close(p[READ]);
	  for(i = 0 ; i < 5 ;i++ )
	{
		sprintf(final,"%d %d %d",i ,i ,i);
		write(p[WRITE],final,50);
		close(p[WRITE]);
		sleep(1);
	  }
	  close(p[WRITE]);

	  waitpid(pid, NULL, 0);
     }

     exit(0);
}
