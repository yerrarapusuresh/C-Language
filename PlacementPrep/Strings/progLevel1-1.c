#include <stdio.h>

int main()
{

	char p[] = "java"	;
	char q[] = {'j','a','v','a'};
	char *r = "java";
	printf("%ld %ld %ld \n",sizeof(p),sizeof(q),sizeof(r));
//	printf("%ld\n",sizeof("suresh"));
}