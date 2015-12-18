#include <stdio.h>

void swap(int * p , int * q)
{
	int temp = * p ;
	*p = * q ;
	* q = temp ;
}
void printArray(int array[],int size)
{
	int i ;
	for( i = 0 ; i < size ;i++)
		printf("%d\t",array[i] );
	printf("\n");
}
void selectionSort(int arr[], int n) {
      int i, j, minIndex, tmp,k;    
      for (i = 0,k= 0; i < n - 1 && k < 4; i++,k++) {
            minIndex = i;
            for (j = i + 1; j < n; j++)
                  if (arr[j] < arr[minIndex])
                        minIndex = j;
            if (minIndex != i) {
                  tmp = arr[i];
                  arr[i] = arr[minIndex];
                  arr[minIndex] = tmp;
            }
      }
}


int main()
{
	int array[] = {36,60,47,69,27,62,24,94,80,68 };
	//printArray(array,5);
	selectionSort(array,10);
	printArray(array,10);
	//swap(array,0,1);

	return 0 ;
}







