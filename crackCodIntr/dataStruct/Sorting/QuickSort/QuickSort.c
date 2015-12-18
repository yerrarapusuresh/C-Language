#include <stdio.h>
#include <stdbool.h>


void swap(int array[] , int i , int j)
{
	int temp = array[i] ;
	array[i] = array[j]  ;
	array[j] = temp ;
}


int partation(int array[] , int low , int high )
{
	int i = low ;
	int j = high + 1 ;


	while(true)
	{
		while(array[low] >= array[++i])
			if(i == high)
				break ;
		while(array[low] <= array[--j])
			if(j == low)
				break ;
		if(i >= j)
			break ;
		swap(array,i,j) ;
	}
	swap(array , low , j);
	return j ;

}

void quicksort(int array[] , int low , int high)
{
	if(low < high)
	{
		int p = partation(array,low,high);
		quicksort(array,low,p-1);
		quicksort(array,p+1,high);
	}
}

void printarray(int array[] ,int size)
{
	int i  ;
	for(i = 0 ; i < size ; i++)
		printf("%d\n",array[i] );
	printf("\n");
}
int quickselect(int array[] , int size , int key )
{
	int i = 0 ;
	int j = size ;
	int p ;
	while(i < j )
	{
		p = partation(array , i , j) ;
		if(p > key) 
			j = p-1 ;
		else if(p < key)
			i = p + 1 ;
		else 
			return array[p];
	}
	return array[key] ;
}






int main()
{
	int array[] = {5,4,3,2,1};
	int size = sizeof(array)/sizeof(array[0]);
	quicksort(array,0,size-1);
	printarray(array,size);
	printf("\n %d \n",quickselect(array,size-1,5));
}














