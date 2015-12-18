#include <stdio.h>
#include <stdlib.h>
int toString(int i)
{
	char * temp = (char *)malloc(sizeof(int) * 3);
	sprintf(temp , "%d",i);
	printf("%s",temp );
	return i ;
}

int main()
{
	int i ;
	int size = 3 ;
	int total = 0 ;
	int numbers[] = {001,010,014};

	for(i = 0; i < size; ++i)
	{
		total += numbers[i] ;
	}

	toString(total);
}