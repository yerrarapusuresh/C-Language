#include <stdio.h>
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

void merge(int array[],int aux[],int low,int mid,int high)
{
	int i , j , k ;
	for( i = low ; i <= high ; i++)
		aux[i] = array[i] ;
	i = low ;
	j = mid + 1 ;
	k = low ;
	while(k <= high)
	{
		if(i > mid)
			array[k++] = array[j++];
		else if( j > high)
			array[k++] = aux[i++];
		else if(aux[j] < aux[i])
			array[k++] = aux[j++] ;
		else
			array[k++] = aux[i++] ;
	}
}



void mergesort(int array[],int aux[],int low , int high)
{
	if(low < high)
	{
		if( high < (low + 7) )
		{
			insertionSort(array,low,high);
			return ;
		}
		int mid = (low + high)/2 ;
		mergesort(array,aux,low,mid);
		mergesort(array,aux,mid+1,high);
		merge(array,aux,low,mid,high);
	}
}

void sort(int array[] , int size)
{
	int * aux = (int *)malloc(sizeof(int)*size);
	mergesort(array,aux,0,size-1);
	free(aux);
}



int main()
{
	int  array[] = {6,2,3,4,3,4,3,11,1,11111,11,1,1111,1111,1,111,1,11,1,5,4,7,5,4,3,4,4,4,4,23,24,25,44,3,4,5,5,6,6,61,2,33,2,3,4,5,66,234};
	printArray(array,SIZE);
	sort(array,SIZE);
	printArray(array,SIZE);
}