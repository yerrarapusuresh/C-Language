#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


void printArray(int array[], int len)
{
	int i ;
	for(i = 0 ; i < len ; i++)
		printf("%d\t",array[i]);
	printf("\n");
}


bool checkUniqueChar(char * str)
{
	static int array[26];
	
	int len = strlen(str);
	int i = 0 ;
	char c ;
	while( i < len)
	{
		c = str[i] ;
		if( ! isalpha(str[i]))
			return false ;

		if(isupper(c))
  			c = (c - 'A')+'a';
		if((++array[str[i]-'a']) > 1 )
			return false ;
		
		i++ ;
	}
	return true ;

}



int main()
{	char str[50];
	memset(str,'\0',50);
	printf("Enter your string to check Unique char or not :");
	scanf("%s",str);
	printf("%s\n",str);
	if(checkUniqueChar(str))
		printf("Given string has Unique chars \n");
	else
		printf("Given string has not contains Unique chars \n");
	return 0 ;
}