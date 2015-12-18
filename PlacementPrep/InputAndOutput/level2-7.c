#include <stdio.h>

int main()
{
	char c ;
	while(c = getchar() != 'a')
		putchar(c);
	return 0 ;
}