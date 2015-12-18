#include <stdio.h>
#include <signal.h>
#include <stdbool.h>

void doubt(int num);

int main()
{
	signal(SIGQUIT , doubt);
	while(true)
	{
		sleep(1);
		
	}
	return 0 ;
}

void doubt (int num)
{
	int static i ;
	++i ;
	printf("You cannot kill me by SIGTERM press Again ^\\ to kill\n");
	if(i == 2)
		kill(getpid(),SIGKILL);
}





