#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
	pid_t pid[2] ;
	int status[2],i;

	if((pid[0] = fork()) == 0)
	{
		sleep(5);
		exit(9);
	}
	else
	{
		if( (pid[1]) = fork() == 0 )
		{
			sleep(3);
			exit(10);
		}
		else
		{
			for( i = 0  ; i < 2 ; i++ )		
				wait(&status[i]);
			printf("this is child process 1 and pid %d\n",pid[0]);
			if(WIFEXITED(status[0]))
				printf("child is exited with code %d\n",WEXITSTATUS(status[0]));
			else
				printf("child 1 is exited abnormal way \n");
			if(WIFEXITED(status[1]))
				printf("child 2 is exited with code %d \n",WEXITSTATUS(status[1]));
			else
				printf("child 2 is abnormal termination \n");
			return 0 ;
		}
	}
}









