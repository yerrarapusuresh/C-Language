#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool checkPerm(char  str1[] , char str2[] )
{
	static int  a[26] ,b[26] ;
	int i = 0 ;


	while(str1[i] != '\0')
	{
		a[str1[i++]-'a']++ ;


	}
	i = 0 ;
	while(str2[i] != '\0')
	{
		b[str2[i++]-'a']++;

	}
	i = 0 ;
	while(i < 26)
	{
		
		if( a[i] != b[i])
			return false ;
		i++ ;


	}

	return true ;

}




int main()
{
	char * str1 = malloc(50);
	char * str2 = malloc(50);

	memset(str1,'\0',50);
	memset(str2,'\0',50);

	printf("Enter you String one \n");
	scanf("%s",str1);

	printf("Enter your String two \n");
	scanf("%s",str2);

	
	printf("%s %s",str1,str2);

	if(checkPerm(str1,str2))
		printf("entered strings is permutation of another \n");
	else
		printf("entered strings is not permutation of another \n");

	return 0 ;
}
















