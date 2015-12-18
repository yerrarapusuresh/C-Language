#include <stdio.h>


void fun(int * p , int * q)
{
	int * temp ;
	temp = p ;
	p = q ;
	q = temp ;

}

int main() 
{

	int a = 10  , b = 20 ;

	int	*p, * q ;
	p = & a ;
	q = & b ;
	fun(p , q) ;
	printf("a = %d , b = %d *p = %d *q = %d ",a, b, *p ,*q);
}