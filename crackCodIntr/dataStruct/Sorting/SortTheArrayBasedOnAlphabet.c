#include <stdio.h>
#include <string.h>
#include <ctype.h>

void quicksort(char  array[] , int low , int high);
int partation(char array[] , int low , int high);
void insertionsort(char array[], int low , int high);
void swap(char array[] , int i , int j)
{
	char temp = array[i] ;
	array[i] = array[j] ;
	array[j] = temp ;
}

int main(int argc , char * argv[])
{
	if(argc != 2)
	{
		printf("Usage:outfile string \n");
		return 0 ;
	}
	int i , j = -1 ;
	for( i = 0 ; i < strlen(argv[1]) ; i++)
	{
		if(islower(argv[1][i]))
		{
			j++ ;
			{
	//			swap(array,i,j) ;
			}
		}
	}
	char array[10];
	strcpy(array,"6543211234");
	//insertionsort(array,0,strlen(array)-1);
	printf("%s\n",array );
	quicksort(array,0,strlen(array)-1);
	printf("%s\n",array);
}

void quicksort(char  array[] , int low , int high)
{
	if(low < high)
	{
		if((high ) < (10 + low)  )
		{
			insertionsort(array,low,high);
			return ;
		}
		int j = partation(array,low,high) ;
		printf("partation = %d\n",j );
		quicksort(array,low,j-1);
		quicksort(array,j+1,high);

	}
}

int partation(char array[] , int low , int high)
{
	char key = array[high] ;
	int i , j = low - 1  ;
	for( i = low ; i < high  ; i++)
	{
		if(array[i] <= key)
		{
			j++ ;
			
			swap(array , i ,j) ;
			
		}
	}
	swap(array,j+1,high) ;
	return (j + 1) ;
}



void insertionsort(char array[], int low , int high)
{
	int i , j , key ;
	for( j = 1 ; j <= high ; j++)
	{
		i = j - 1 ;
		key = array[j] ;
		while(i >= low && key  < array[i])
		{
			array[i + 1] = array[i];
			i--;
		}
		array[i+1] = key ;
	}
}







