#include <stdio.h>
#include <string.h>

int main(int argc , char * argv[])
{
	if(argc < 2)
	{
		printf("Usage: ./prog inputfile\n");
		return 0 ;
	}

	FILE * fp ;
	fp = fopen(argv[1],"r");
	char c ;
	int i = 0 ;
	char buff[1000];
	memset(buff,'\0',1000);

	if(fp == NULL)
	{
		printf("Error: Input file could not opend \n");
		return 0 ;
	}
	while((c = fgetc(fp)) != EOF)
	{
		buff[i++] = c ;
	}
	
	
	return 0 ;
		



}