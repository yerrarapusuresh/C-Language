#include <stdio.h>
#include <string.h>

int main()
{

	char s[] = "language\0\0\0"	;
	printf("%ld %ld \n",sizeof(s),strlen(s));
}