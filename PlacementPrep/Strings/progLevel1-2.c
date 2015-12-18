#include <stdio.h>

int main()
{
	char s[] = "c\0java"	;
	char p[] = "abc\0\0";
	printf("%s %s \n",s,p);
	//printf("%ld\n",sizeof(p));
}