#include <stdio.h>

int exp(int, int ) ;
int main()
{
	int x, y ; 
	x = 3 ; 
	y = 5 ;
	printf("%d",exp(x,y));
}
int exp(int a , int b)
{
	if(b==1)
		return a ;
	else 
		return a + exp(a,b-1);
}
