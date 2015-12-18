#include <stdio.h>

int main()
{
	printf("%ld\n","abcdef");
	printf("%ld\n",&"abcdef"+1);
}