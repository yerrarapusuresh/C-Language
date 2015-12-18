#include <stdio.h>

struct node_s
{
	int element ;
	struct node_s * next ;
};

int main()
{
	struct node_s *p,*q ;
	p = malloc(sizeof(*p));
	q = malloc(sizeof(*q));

	p->element = 10 ;
	p->next = q ;
	q->element = -15 ;
	q->next = NULL ;
	printf("%d \n",p->element);
	p = p->next ;
	printf("%d\n",p->element );
	return 0 ;
}