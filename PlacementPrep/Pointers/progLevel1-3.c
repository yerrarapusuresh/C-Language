#include <stdio.h>

int main()

{
	int r,*p = NULL ;
	r = *p++ ;
	printf("%d\n",r);
	return 0 ;
}
