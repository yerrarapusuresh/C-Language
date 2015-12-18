#include <stdio.h>

void fun()
{
	#define fun() i = 20 ;
}


int main()
{
	int i = 10 ;
	fun();
	printf("%d\n",i);
}