#include <stdio.h>
int strlen(char * str);

int main(void)
{
	char *s = "sures is good boy ";
	
	printf("%s\n",s);
	int n = strlen(s) - 1 ;
	while(n >= 0)
	{
		printf("%s\n",&s[n]);
		n--;
	}
	
}


int strlen(char * str)
{
	int count = 0 ;
	while (str++)
	{
		count++ ;
		
	}
	return count ;
}
