#include <stdio.h>
#include <stdlib.h>

int random_partation(int array[],int p , int r);
int partation(int array[],int p , int r);
void swap(int* , int*);
void printArray(int array[], int size );
void random_quicksort(int array[], int p , int r );

int main()
{
    int array[] = {2,8,7,1,3,454,0000,545,45,45,4,54,5,5,6,4,34,56,23,56} ;
 
    printArray(array,(sizeof(array)/sizeof(int)));

    random_quicksort(array,0,19);

    printArray(array,(sizeof(array)/sizeof(int)));

//    printf("\n\n%d\n",i);

    return 0 ;


}

int partation(int array[], int p , int r )
{
    int x = array[r] ;
    int i = p - 1 ;
    int j ;

    for( j = p ; j < r ; j++ )
    {
       if( array[j] <= x ) 
       {
            i++;
            swap( &array[i], &array[j]);
       }
    }
    swap( &array[i+1] ,& array[r] );
    return i + 1 ;

}

void swap(int * num , int * num2 )
{
    int temp = *num ;
    *num = *num2 ;
    *num2 = temp ;
}


void printArray(int array[], int size )
{
    int i ;
    for(i = 0 ; i < size ; i++)
        printf("\t%d",array[i]);
    printf("\n");
}

void random_quicksort(int array[],int p , int r)
{
    if ( p < r )
    {
       int q = random_partation(array,p,r); 
       random_quicksort(array,p,q-1);
       random_quicksort(array,q+1,r);
    }
}


int random_partation( int array[],int p ,int r )
{
    int i =p+ rand()%(r+1-p) ;
    swap(&array[r],&array[i]);
    return partation(array,p,r);
    
}







