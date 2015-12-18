#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
void printArray(bool array[] ,int size)
{
    int i ;
    for( i = 0 ; i < size ; i++)
        printf("%d\t",array[i]);
    printf("\n");
}
void mark(bool array[],int size , int j)
{
  int   i = j+j ;
    for(; i < size ; i += j)
        array[i] = 1 ;
}
int findPrimes(bool array[] , int size)
{
    int i = 2 ;
    int res = 0 ;
    for( i = 2 ; i < size ;i++)
        if(array[i] == 0)
        {
            mark(array,size,i);
            res += i ;
        }
    //printArray(array,size);
    return res ;
}


int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int size ;
    scanf("%d",&size);
    while(size--)
    {
        int input ,i;
        scanf("%d",&input);
        input++ ;
        bool array[input];
        for( i = 0 ; i < input ; i++)
        	array[i] = false ;
      // printArray(array,size);
        printf("%d\n",findPrimes(array,input));
        
    }
    return 0;
}
