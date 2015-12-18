#include <stdio.h>
#include <string.h>

int my_strcmp ( char *s, char *t ) {

	while ( *s == *t ) {
		if (*s == '\0')
			return 0 ;
		s++ ;
		t++ ;
	}

	return (*s - *t) ;
}

int main()
{
	printf("%d\n",strcmp("suresh","sureshEnd"));
	printf("%d\n",my_strcmp("suresh","sureshEnd"));
}