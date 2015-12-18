#include <stdio.h>

int main()
{
	int i = +5, j = +4 , k ;
	k = i++ * j++ ;
	printf("%d  %d %d ",i,j,k);
	return 0 ;
}
