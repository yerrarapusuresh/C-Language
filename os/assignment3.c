#include<stdio.h>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>

int  main(int argc,char *argv[])
{
	if(argc != 3 )
	{
		printf("Usage :./program command1  command2 \n");
		return -1 ;
	}
	double totalTime;
	pid_t pid;
	clock_t init,stop;	
 	init = clock();
	if( (pid=vfork()) == 0 )
	/*Child is starts executes from parent process address space*/

	{
		sleep(2);
	  
            execlp(argv[1],argv[2],NULL); 
	}
	else
	{
    	         wait(NULL);
		 stop = clock();
 		 printf("\n\n\t%f\n",difftime(stop,init)/CLOCKS_PER_SEC);

	}

	return 0 ;

}
