#include <stdio.h>
int strlen(char * );
int main(void)

{
	char * str = "suresh";
	printf("%d",strlen(str));	
	return 0 ;
}

int strlen(char * str)
{
	if (str == '\0')
		return 0 ;
	else 
		return 1 + strlen(++str) ;
}
