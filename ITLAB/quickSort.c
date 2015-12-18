#include <stdio.h>

int partation(int array[],int p , int r);
void swap(int* , int*);
void printArray(int array[], int size );
void quicksort(int array[], int p , int r );

int main()
{
    int array[] = {2,8,7,1,3,5,6,4} ;
 
    printArray(array,(sizeof(array)/sizeof(int)));

    quicksort(array,0,7);

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

void quicksort(int array[],int p , int r)
{
    if ( p < r )
    {
       int q = partation(array,p,r); 
       quicksort(array,p,q-1);
       quicksort(array,q+1,r);
    }
}










