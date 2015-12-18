#include <stdio.h>

void sort(int  array[] , int p , int r);
int partation(int  array[] , int p , int r) ;
void swap(int array [], int i , int j);
void printArray(int array[] , int size)
{
	 int i ;
	 for( i = 0 ; i < size ; i++)
	 	printf("%d\t",array[i]);
	 printf("\n");
}
int main()
{
	int array[] = { 5,5,4,4,3,2,3,3,4,4};
	sort(array, 0 , (sizeof(array)/sizeof(array[0]))-1);
	printArray(array,sizeof(array)/sizeof(array[0]));


}

void sort(int  array[] , int p , int r)
{
	if(p < r)
	{
		int q = partation(array , p , r);
		sort(array , p , q-1);
		sort(array , q + 1 , r);

	}
}

int partation(int  array [], int p , int r)
{
	int x = array[r] ;
	int i = p - 1 ;
	int j  ;
	for(j = p ; j < r; j++)
	{
		if(array[j] < x)
		{
			i++ ;
			swap(array , i , j);
		}
	}
	swap(array , i+1 , r);
	return i+1 ;

}

void swap(int  array [], int i , int j )
{
	int temp = array[i]  ;
	array[i] = array[j] ;
	array[j] = temp ;
}










