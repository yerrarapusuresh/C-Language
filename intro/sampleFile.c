#include <stdio.h>

int main()
{
	FILE * fp ;
	char buffer[11] ;
	fp = fopen("input.txt","r") ;
	while(fgets(buffer,11,fp) != NULL)
		printf("%s\n",buffer);
	fclose(fp);
}
