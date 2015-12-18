#include <stdio.h>
#include <string.h>

void strcmpr(const char source[],char desti[])
{
	int i , j ,res;
	char buff[10] ;
	for(i = 0 ; source[i] != '\0' ; )
	{
		if(source[i+1] != '\0')
			j = i + 1 ;
		while(source[j] != '\0' && source[i] != source[j++] );
		res = j - i ;
		printf("%c%d",source[i] , res);
		memset(buff,'\0',10);
		sprintf(buff,"%c",source[i]);

		strcpy(desti,buff);
		memset(buff,'\0',10);
		sprintf(buff,"%d",res);
		strcpy(desti,buff);
		i += j ;

	}
}


int main()
{
	char * str = "aaabbbccc" ;
	char  res[10] ;

	memset(res,'\0',10);
	strcmpr(str,res);
	printf("%s\n",res );
	return 0 ;
}