#include <stdio.h>
#include <stdlib.h>

int f(int *p)
{
	int i , s = 0 ;
	for(i = 0 ; i < sizeof(p);i++)
		s+= *(p+i);
	printf("%d \n",s);
	return s ;
}

int main()
{
	int i , r ;
	static int *a ;
	a = malloc(5*sizeof(int));
	for(i = 0 ;i < 5 ;i++)
	*(a+i) = i+1 ;
	for(i = 0 ; i < 5 ;i++)
		printf("%d \t",a[i]);
	printf("\n\n\n%d\n",sizeof(a)/sizeof(a[0]));
	r = f(a) ;
	free(a);
	printf("%d\n",r);
}
