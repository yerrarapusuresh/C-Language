#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 1000000

int main (void)
{
     int pid[3], i, j, buffer[MAXSIZE], p;
	printf("this is main program pid is %d \n",getpid());

     for (i=0; i<3; i++) {
	  if ((pid[i] = fork()) == 0) {
	       printf("Child No. %d; PID: %d; PPID %d\n",  i, getpid(),getppid());
	       for (j=i*MAXSIZE/10; j<(i+1)*MAXSIZE/10; j++) {
		    buffer[j] = j;
	       }
	       p = 0;
	     //  break;
	  }// else
	       //p = 1;
     }

    // if (p == 1) {
	  for (i=0; i<3; i++)
	      wait ( NULL);

	  for (i=0; i<MAXSIZE; i++)
	       if (buffer[i] != i)
		   // printf("Error at %d (buffer[%d] = %d)\n", i, i, buffer[i]);
 //    }

     exit(0);
}
