#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
pthread_t ntid ;
void *thr_fn(void *arg);
void printids(const char * s);

int main()
{
	int errNum ;
	
	errNum = pthread_create(&ntid , NULL,thr_fn,NULL);
	if( errNum != 0)
	{
		printf("This process could not create thread \n");
	}
	sleep(1);
	printids("this is main : ");
	printf("(0x%x) \n",ntid);
//	sleep(1);
	exit(0);
}


void * thr_fn(void * arg)
{
	printids("New thread :");
	ntid = 0 ;	
	return ((void *)0);
}
void printids(const char *s)
{
	pid_t pid ;
	pthread_t tid ;
	pid = getpid();
	tid = pthread_self();
	printf("%s pid %u tid %u (0x%x)\n",s,(unsigned int)pid,(unsigned int)tid,(unsigned) tid);

}










