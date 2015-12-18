#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int myPipe[2] ;
	int ret ;
	pid_t pid ;
	ret = pipe(myPipe);
	if(ret == -1)
	{
		perror("file could not created \n");
		return 0 ;
	}
	
	pid = fork();
	if(pid == 0)
	{
		char buff[] = {"This suresh first program about Pipe\n"};
		write(myPipe[1],buff,sizeof(buff));
		exit(0);
	}
	else
	{
		char buff[300] ;
		read(myPipe[0],buff,300);
		printf("%s \n",buff);
		exit(0);
	}
}
