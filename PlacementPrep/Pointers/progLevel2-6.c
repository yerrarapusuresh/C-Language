#include <stdio.h>

int * f()
{
		int a = 6 ;
		int *b = NULL ;
		b = &a ;
		return b ;	
}

main()
{
	int *p = NULL ;
	p = f();
	printf("%d\n",*p);
}