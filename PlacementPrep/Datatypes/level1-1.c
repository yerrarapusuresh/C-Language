#include <stdio.h>

int main()
{
	int a = (1 << 31)-1;
	++a;
	printf("%d  \n",a);
}
