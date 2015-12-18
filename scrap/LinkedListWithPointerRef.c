#include <stdio.h>
#include <stdlib.h>

struct node 
    {
        int data ;
        struct node * next ;
    } ;
    
void Push(struct node ** head , int data);
void Length(struct node * current)    ;
void Mem_free(struct node * head );

int main()
{
    struct node * head = NULL;
    Push(&head , 1);
    Push(&head,2);
    Length(head);
    Mem_free(head);

    return 0 ;
}

void Push(struct node ** head , int data)
{
    struct node * newNode = malloc(sizeof(struct node ));
    newNode -> data = data ;
    
    if(*head == NULL)
    {
       
        *head = newNode ;
    }
    else
    {
        newNode -> next = *head ;
        *head = newNode ;
    }
}
void Length(struct node * current)
{
    int len = 0 ;
    while(current != NULL)
    {
        len++ ;
        current =current -> next;
    }
   printf("%d\n",len);
}
void Mem_free(struct node * head )
{
    struct node * temp = head ;
    while(head != NULL)
    {
        temp = head ;
        head = head -> next ;
        free(temp);
    }
}

