#include <stdio.h>

void fun(char a[])
{
	a[0] = 'A' ;
}

int main()
{
	fun("abcd");
}

