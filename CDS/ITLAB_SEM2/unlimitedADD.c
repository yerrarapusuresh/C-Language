#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct input
{
	int  array[1000] ;
	int len ;

} Input ;

int printArray(Input *  a)
{
	int i  ;
	for( i = 0 ; i < a->len ; i++)
		printf("%d",a->array[i]);
	printf("\n");
	
}
void intStrRev(int * array , int len)
{
	int i,j  ; 
	for(i = 0 , j = len-1 ; i < j ; j--,i++)	
	{
		int temp = array[i];
		array[i] = array[j] ;
		array[j] = temp ;
	}
}
void add(Input *a , Input * b , Input *res)
{
	int i,carry = 0  ;
	for(i = 999 ; i >= 0 ; i--)
	{
		res->len++ ;
		if(a->array[i] + b->array[i] > 9)
		{
			res->array[i] = (a->array[i]+b->array[i])%10;
			carry = (a->array[i]+b->array[i])/10 ;
		}
		else
		{
			res->array[i] = (a->array[i]+b->array[i]) + carry ;
			carry = 0 ;
		}
	}
}
int main()
{
	Input a , b , res ;
	int i,j ;

	printf("How many integers for array 1\n");
	scanf("%d",&a.len);
	getchar();

	
	
	memset(a.array,0,1000);
	printf("enter number now\n");
	 j = 999;
	while( (i = getchar()) != '\n') 
	{
		a.array[j--] = i-'0';
		
	}
	intStrRev(&a.array[j],1000-j+1);

	printArray(&a);

	printf("How many integers for array 2\n");
	scanf("%d",&b.len);
	getchar();

	
	
	memset(b.array,0,1000);

	printf("enter number now\n");
	 j = 999;
	while( (i = getchar()) != '\n') 
	{
		b.array[j--] = i-'0';
		
	}
	intStrRev(&b.array[j],1000-j+1);
	memset(res.array,0,1000);
	printArray(&b);
	add(&a,&b,&res);
	printf("\n\n\n\n");
	res.len= 1000 ;
	printArray(&res);
}