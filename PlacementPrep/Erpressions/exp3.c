#include <stdio.h>

int f()
{
	printf("f");
	return 1 ;
}
int g()
{
	printf("g");
	return 2 ;
}
int h()
{
	printf("h");
	return 3 ;
}
int main()

{
	int r  ; 
	r = f() + g() * h();
	printf("%d \n",r);
	return 0 ;
}
