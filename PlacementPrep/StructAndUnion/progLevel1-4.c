#include <stdio.h>

struct test 
{
	int a ;
	int b ;
};
void f(struct test t) 
{
	t.a = 10 ;
	t.b = 15 ;
}

main()
{
	struct test t = {4,5};
	f(t);
	printf("%d , %d \n",t.a , t.b);
}