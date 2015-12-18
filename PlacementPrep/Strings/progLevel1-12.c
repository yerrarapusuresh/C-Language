#include <stdio.h>
#include <string.h>

int main()
{
	char s[] = "Algorithmica";
	printf("%c",*(s+strlen(s)));
	return 0 ;
}