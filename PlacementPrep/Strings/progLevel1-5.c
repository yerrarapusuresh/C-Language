#include <stdio.h>

int main()
{

		char * s = "yahoo";	
		printf("%ld %ld\n",sizeof("yahoo"),sizeof(*s));
}