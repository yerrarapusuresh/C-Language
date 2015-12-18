#include <stdio.h>
#include <string.h>

int strCmp(char * a , char * b )
{
	int cmp ;
	while(*a == *b &&( *a != '\0' && *b != '\0'))
	{
		a++ ;
		b++ ;

	}

	if((*a == '\0') && (*b == '\0'))
	{
		cmp = 0;
	}
	else if(*a < *b)
		cmp = -1 ;
	else
		cmp = 1;
	return cmp ;
}




int main()
{
	printf("%d",strCmp("suresh","suresh") ==strcmp("suresh","suresh"));
	printf("%d",strCmp("suresh","ramesh") == strcmp("suresh","ramesh"));
	printf("%d",strCmp("\0","suresh") == strcmp("\0","suresh"));
	printf("%d",strCmp("ramesh","suresh") == strcmp("ramesh","auresh"));
}
