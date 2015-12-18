#include <stdio.h>

void swap(int array[] , int a , int b)

{
	int temp = array[a] ;
	array[a] = array[b] ;
	array[b] = temp ;
}

void QuickSort(int array[] , int low , int high)
{
	if(high <= low ) 
		return ;

	int v = array[low] ;
	int lt = low ;
	int gt = high ;
	int i = low ;
	{
		while(i <= gt)
		{
			if(array[i] < v )
				swap(array,lt++,i++);
			else if(array[i] > v)
				swap(array,gt--,i);
			else 
				i++ ;
		}
	}
	QuickSort(array,low,lt-1) ;
	QuickSort(array,gt+1,high) ;
}

printArray(int array[] , int size)
{
	int  i ;
	for(i = 0 ; i < size ;i++)
		printf("%d\t",array[i]);
	printf("\n");

}
int main()
{
	int array[] = {6,5,4,5,6,7,6,5,4,3,3,2,3,4,5,6,7,8,9,0,9,8,8,7,6,6,5,5,4,4,3,3,3};
	/*int i ;
	for( i = 0  ; i < 20 ; i++)
	{
		scanf("%d",&array[i]);
	}*/
	int size = sizeof(array) / sizeof(array[0]) ;
	printArray(array,size);
	QuickSort(array,0,size-1);
	printArray(array,size);
	return 0 ;
}















