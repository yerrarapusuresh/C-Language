#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strLen(char * s)
{
	int i = 1 ;
	while((*s++ != '\0' )&& i++) ;
	return i -1 ;
}
void strRev(char * s)
{
	int i , j = strLen(s) - 1 ;
	char temp ;
	for(i = 0 ,j ; i < j; i++,j-- )
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp ;
	}
}


int main()
{
	char * input = malloc(50) ;
	memset(input,'\0',50);

	printf("Enter a string to reverse \n");
	scanf("%s",input);

	strRev(input);
	printf("%s\n",input);



}