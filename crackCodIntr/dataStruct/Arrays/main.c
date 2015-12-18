#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array.h"


int main()
{
	int size ,target;
	printf("enter size of an array \n");	
	if(scanf("%d",&size) == 0)
		return 0 ;
	int * array = (int *) malloc(sizeof(int) * size);
	if(!getInput(array , size))
		return 0 ;
	
	
	printf("enter an element to find: \n");
	scanf("%d",&target);
	printf("%d\n",hasArrayTwoCandidates(array,size,target));
	printArray(array,size);
	//binarySearch(array,target,size);
	free(array);
	return 0 ;
}