#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("Enter number element into file\n");
	int input ;
	scanf("%d",&input);
	int i ;
	FILE * fp ;
	fp = fopen("input.txt","w");
	for(i = 1 ; i <= input ; i++ )
	{
		fprintf(fp,"%d",rand()%10);
	}
}