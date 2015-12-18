#include <stdio.h>
#include <stdlib.h>

struct node
    {
        int data ;
        struct node * next ;
    };
void push(struct node ** headRef, int data);
void length(struct node * head );
int main()
{
    struct node * head = NULL ;
    struct node * tail ;
    int i ;
    push(&head,99);
    tail = head ;
    for( i = 0 ; i < 10 ; i ++)
    {
        push((&tail -> next), i);
        tail = tail -> next ;
    }
    
    struct node * current = head;
    while(current != NULL)
    {
        printf("%d \n",current->data);
        current = current -> next ;
    }
    length(head);
    current = head ;
    while(head != NULL)
    {
        current = head ;
        head = head -> next ;
        free(current);
        
    }

}

void push(struct node ** headRef, int data )
{
    struct node * newnode = malloc(sizeof(struct node ));
    newnode -> data = data ;
    newnode -> next = *headRef ;
    *headRef = newnode ;
    
}

void length(struct node * head )
{
    int count = 0 ;
    while (head != NULL)
    {
        count ++ ;
        head = head -> next ; 
        
    }
    
    printf("%d\n",count);
}
