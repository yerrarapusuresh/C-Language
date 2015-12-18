#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE sizeof(array)/sizeof(array[0])

void printArray(int array[],int size)
{
	int i ;
	for( i = 0 ; i < size ; i++)
		printf("%d\t",array[i]);
	printf("\n");
}
void insertionSort(int array[], int low ,int high)
{
	int i , j , key ;
	for( j = low + 1 ; j <= high ; j++)
	{
		i  = j - 1 ;
		key = array[j] ;
		while((i >(low-1)) && (array[i] >key))
		{
			array[i+1] = array[i];
			i--;
		}
		array[i+1] = key ;
	}

}

void merge(int a[],int aux[],int low,int mid,int high)
{
	int i , j ,k ;
	i = low ;
	j = mid+1 ;
	k = low ;
	while(k <= high)
	{
		if(i > mid)
			aux[k++] = a[j++];
		else if( j > high)
			aux[k++] = a[i++];
		else if(a[j] < a[i])
			aux[k++] = a[j++] ;
		else
			aux[k++] = a[i++] ;
	}
}



void mergesort(int array[],int aux[],int low , int high)
{
	
		

	if(high <= low)
		return ;
	
		int mid = low + (high - low)/2 ;
		mergesort(aux,array,low,mid);
		mergesort(aux,array,mid+1,high);
		merge(array,aux,low,mid,high);
	
	
}

void sort(int array[] , int size)
{
	int * aux = (int *)malloc(sizeof(int)*size);
	memcpy(aux,array,size);
	mergesort(array,aux,0,size-1);
	free(aux);
}



int main()
{
	int  array[] = {34,32,21,3,4,32,3,4,6,2,8};
	printArray(array,SIZE);
	sort(array,SIZE);
	printArray(array,SIZE);
}