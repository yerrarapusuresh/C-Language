#include <stdio.h>

int main()
{
	char s[] = "Algorithmica";
	printf("%c\n",(*s)++);
	printf("%c",++*s);
}
