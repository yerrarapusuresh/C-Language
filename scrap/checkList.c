#include <stdio.h>
#include <stdlib.h>

struct node 
{
     int data ;
     struct node * next ;
};

void makeNull(struct node* headRef);
void test();

int main()
{
    test();
}

void test()
{
    struct node * head1 = malloc(sizeof(struct node)) ;
    struct node * head2 = malloc(sizeof(struct node));
    
    makeNull(head1);
    makeNull(head2);
    
        printf("yes it is working :)%d",head2 -> data);
    
}

void makeNull(struct node* headRef)
{
    headRef -> data = 13;
    headRef -> next = NULL;
    
}
