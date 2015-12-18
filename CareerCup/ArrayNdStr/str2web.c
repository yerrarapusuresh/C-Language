#include <stdio.h>
#include <string.h>

int main(int argc , char * argv[])
{
	FILE * fp ;
	char c ;
	char buff[1000];
	memset(buff,'\0',1000);
	printf("%d\n",strlen(buff));
	int i = 0 ;
	if(argc < 2)
	{
		printf("Usage: input file should priovde\n");
		return 0 ;
	}

	fp = fopen(argv[1],"r");

	while((c = fgetc(fp)) != EOF)
	{
		buff[i++] = c ;
	}
	buff[i-1] = '\0';


	fclose(fp);
	return 0 ;
} 
