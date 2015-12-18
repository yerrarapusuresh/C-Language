#include <stdio.h>
#include <stdlib.h>

struct node 
{   int data ;
    struct node * next ;
} ;
void push(struct node ** headRef, int data );
void linkWalk(struct node * head);
void mem_free(struct node * original);
void copyWithPush(struct node * head );



int main()
{
    struct node * head = NULL ;
    struct node * newList = NULL ; 
    struct node * tail = NULL ;
    
        
    int i ;
    
    for( i = 0 ; i < 10 ; i++)
        push(&head,i);
    linkWalk(head);
    struct node * temp = head ;
    
    while (temp != NULL) 
    {
        if(newList == NULL)
        {
            newList = malloc(sizeof(struct node));
            newList -> data = temp -> data ;
            tail = newList ;
        }
        else 
        {
            tail -> next = malloc(sizeof(struct node ));
            tail = tail -> next ;
            tail -> data = temp -> data ;
            tail -> next = NULL;
        }
        temp = temp -> next ;
    }
    
    linkWalk(newList);
    copyWithPush(newList);
    mem_free(head);
    mem_free(newList);
    
    
    
}

void push(struct node ** headRef, int data )
{
    struct node * newNode = malloc(sizeof(struct node ));
    newNode -> data = data ;
    newNode -> next = *headRef ;
    *headRef = newNode ;
}

void linkWalk(struct node * head)
{
    struct node * current = head ;
    while(current != NULL)
    {
        printf("%d \n",current -> data);
        current = current -> next ;
    }
}

void mem_free(struct node * head)
{
    struct node * temp ;
    while(head != NULL)   
    {
        temp = head ;
        head = head -> next ;
        free(temp);   
    }
}

void copyWithPush(struct node * original)
{
    struct node * newList = NULL ;
    struct node * current = original ;
    struct node * tail = NULL ;
    while(current != NULL)
    {
        if( newList == NULL)
        {
            push(&newList , current -> data) ;
            tail = newList ;
        }
        
        else 
        {
            push(&(tail->next),current -> data );
            tail = tail -> next ;
        }
    current = current -> next ;
    
    }
    linkWalk(newList);
    mem_free(newList);
    
}






