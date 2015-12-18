#include <stdio.h>


void insert(int array[], int low , int high)
{
	if(low <= high)
{
	int mid = (low + high ) / 2;
	printf("%d\n",array[mid] );
	insert(array,low, mid-1);
	insert(array, mid + 1,high);
}
}

int main()
{
	int array[] = {1,2,3,4,5,6,7};
	insert(array,0,(sizeof(array)/sizeof(array[0])) - 1);

}