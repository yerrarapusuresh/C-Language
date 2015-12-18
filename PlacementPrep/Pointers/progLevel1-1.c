#include <stdio.h>

int main()
{
	int a = -10 , b = -2 ;
	int c ,*pa, * pb ;
	pa = & a ;
	*pa = 2 * a ;
	pb = &b ;
	c = 3*(*pb - *pa) ;
	printf("%d %d \n",a,c);
	return 0 ;
}
