#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct foo
{
	int a , b, c, d ;

};

void printfoo(char * s , struct foo * fp);
void * thr_fun1(void * arg);
void * thr_fun2(void * arg);

int main()
{
	int err ;
	pthread_t tid1 ;
	pthread_t tid2  ;
	struct foo * fp ;
	
	err = pthread_create(&tid1,NULL,thr_fun1,NULL);
	if( err != 0)
	{
		printf(" tid1 could not created \n");		
		
	}
	


	err = pthread_join(tid1,(void*)&fp);
	if( err != 0)
		printf("join 1 could not done \n");
	
	sleep(1);
	printf("parent starting second thread \n");
	
	err = pthread_create(&tid2,NULL,thr_fun2,NULL);
	if( err != 0 )
		printf("tid2 could not created \n");
	pthread_join(tid2,(void*)&fp);
	sleep(1);
	printfoo("parent : \n",fp);
	exit(0);
	
}



void *thr_fun1(void * arg)
{
	struct foo f = { 1,2,3,4};
	printfoo("thread 1 : \n",&f);
	pthread_exit((void *)&f);
}
void * thr_fun2(void * arg)
{
	printf("thread 2 : id %d\n",pthread_self());
	struct foo f = {4,3,2,1};
	printfoo("this is thread 2 ",&f);
	pthread_exit((void *)&f);
}

void printfoo(char * s , struct foo * fp)
{
	printf(s);		
	printf("Structure at 0x%x \n",(unsigned)fp);
	printf("foo.a %d \n",fp->a);
	printf("foo.b %d \n",fp->b);
	printf("foo.c %d \n",fp->c);
	printf("foo.d %d \n ",fp->d);

}


