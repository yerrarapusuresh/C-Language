#include "array.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int linearSearch(int array[] ,int target , int size)
{
	int i ;
	for( i = 0 ; i < size ; i++)
		if(array[i] == target)
		{
			printf("element found in index %d\n",i );
			return i ;
		}

	printf("element not found \n");
	return -1 ;
}

void printArray(int array[], int size)
{
	if(size < 1)
	
		printf("Array is empty . nothing to print\n");
	else
	{
		int i = 0 ;
		for( i = 0 ; i < size ; i++)
			printf("%d\t",array[i]);
		printf("\n");
	}
}

int getInput(int array[] , int size)
{
	if(size < 1)
	{
		printf("array size should be grater than 0\n");
		return 0 ;
	}
	int i  ;
	for( i = 0 ; i < size ; i++)
	{
		printf("\nenter element %d :",i+1 );
		scanf("%d",&array[i]);
	}

	return 1 ;
}

int binarySearch(int array[] , int target , int size)
{
	int  low  = 0 , high = size -1 ,mid = (low + high) / 2;
	while(low <= high )
	{
		if(array[mid] == target)
		{
			printf("target found at %d", mid) ;
			return mid ;
		}
		else if(array[mid] < target)
			low = mid + 1 ;
		else 
			high = mid  - 1 ;
		mid = (low + high) / 2 ;

	}
	
	printf("targer not found \n");
	return -1 ;

}
int hasArrayTwoCandidates(int array[] , int size ,int target)
{
	int low  = 0 ; 
	if(size < 1)
	{
		fprintf(stderr,"size of array should be greater than zero %d",size);
		return -1;
	}
	sort(array,size);

	int high = size -1 ;

	while(low < high)
	{
		if((array[low] + array[high]) == target)
			return 1 ;
		else if((array[low] + array[high]) < target)
			++low ;
		else
			high++ ;
	}
	return -1 ;

}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


void sort(int array[] , int size)
{
	qsort(array,size,sizeof(int),cmpfunc);
}








