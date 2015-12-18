#include <stdio.h>

void strrev(char str[]);
int strlen(char *str);

int main()
{
	char str[10] ;
	scanf("%s",str);
	strrev(str);
	printf("%s\n",str);
	
}

void strrev(char str[])
{
	int i , j ,temp ;
	for( i = 0 , j = strlen(str) - 1 ; i < j ; i ++, j--)
	{
		temp = str[i] ;
		str[i]  = str[j] ;
		str[j] = temp ;
		
	}
}

int strlen(char * str)
{
	if(str != '\0' )
		return 1 + strlen(++str);
	else 
		return 0 ;
}
