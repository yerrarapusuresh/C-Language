#include <stdio.h>


struct node 
{
	int i ;
	struct node * next ;
};

int main()
{
	struct  node  node ;
	struct node * p ;
	printf("%d",sizeof(struct node));
	printf("%d",sizeof(*p));
}