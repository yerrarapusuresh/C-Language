#include <stdio.h>

int main()
{

	char a[] = "language"	;
	char p, *s ;
	s = a;
	printf("%c\n",*(s++));
	p = *++s ;
	printf("%c",p);
	return  0 ;
}