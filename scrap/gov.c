#include <stdio.h>

int x = - 3 ;

int f(void)
{
	x = x+ 2 ;
	return x ;
}

int g(void)
{
	x = x * 3 ;
	return x ;
}

int main()

{
	printf("%d\n",f()+g());
	return 0 ;
}
