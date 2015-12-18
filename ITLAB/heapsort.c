#include <stdio.h>

void Max_Heapify(int array[], int key);
void Build_Max_Heap(int array[]);
void HeapSort(int array[]);
void swap( int * num_one , int * num_two );
int Right(int number);
int Left(int number);
int Parent(int number);

int Array_Size ;
int Heap_Size ;


int main()
{
	
	int i ;
	int array[] = {0,78,56,0,7,-7,67,34,567,34};
	Array_Size = 10 ;
	HeapSort(array);
	for(i = 0 ; i < 10 ; i++)
		printf("%d\n",array[i]);
	return 0 ;
}

void swap(int * num_one , int * num_two)
{
	*num_one = *num_one ^ *num_two ;
	*num_two = *num_one ^ *num_two ;
	*num_one = *num_one ^ *num_two ;
}

int Right(int number)
{
	return number << 1 ;
}

int Left(int number)
{
	return (number << 1 ) + 1  ;
}

int Parent(int number)
{
	return number/2 ;
}

void Max_Heapify(int array[] , int key)
{
	int right = Right( key );	
	int left = Left (key );
	int largest ;
	if( (left < Heap_Size ) && (array[key] < array[left])) 
		largest = left ;
	else 
		largest = key ;
	if( (right < Heap_Size )  && (array[largest] < array[right]) )
		largest = right ;
	if (key != largest )
	{
		swap( &array[largest] , &array[key] );
		Max_Heapify( array , largest );
	}

} 

void Build_Max_Heap( int array[] )
{
	int i ;
	int half = Array_Size / 2 ;
	Heap_Size = Array_Size ;

	for( i = half ; i >= 0 ; i--)
		Max_Heapify(array , i);
}

void HeapSort(int array[])
{
	int i ;
	Build_Max_Heap(array);
	for( i = Array_Size -1  ; i > 0 ; i-- )
	{
		swap( &array[i] , &array[0]);
		Heap_Size -- ;
		Max_Heapify(array, 0);
	}
}













