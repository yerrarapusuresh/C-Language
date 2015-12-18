#include <stdio.h>

void test(void)
{
	printf("Algorihamica\n");
}

int main()
{

	void (*f)(void)	;
	f = test ;
	(*f)();
	f();
}