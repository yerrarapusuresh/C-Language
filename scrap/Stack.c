#include <stdio.h>
#include <stdlib.h>

struct node
    {
        int data;
        struct node * next ;
    };
    
struct node * root = NULL;

void appendTest();
struct node* BuildList();
void append(struct node **headRef , int data);
int lenth(struct node * head);
void lenthTest();
int main()
{
    appendTest();
    lenthTest();
}

struct node* BuildList()
{
    struct node * head =  root ;
    return head ; 
}

void append(struct node **headRef , int data)
{
    struct node * newNode = malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    struct node * current = *headRef ;
    if(*headRef == NULL)
    {
        *headRef = newNode ;
    }
    else
    {     
        newNode -> next = *headRef ;
        *headRef = newNode ;
   }
    
    while(current != NULL)
        {
            printf("---%d\n",current -> data);
            current = current -> next ;
        }
}

void appendTest()
{
    struct node * head = BuildList();
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    
}

int lenth(struct node * head)
{
    struct node * current = head ;
    int count = 0  ;    
    while(current != NULL)
    {
        count++;
        current = current -> next ;      
     
    }
    
    return count;
    
}

void lenthTest()
{
    struct node * head = BuildList ();
    printf("%d",lenth(head));
}














