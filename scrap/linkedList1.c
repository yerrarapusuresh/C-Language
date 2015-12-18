#include <stdio.h>
#include <stdlib.h>

struct node
    {
        int data;
        struct node* next ;
    };

void lenthTest();
struct node* buildList();
int lenth(struct node* head);

int main()
{
    lenthTest();    
}

struct node* buildList()
{
    struct node* head = malloc(sizeof(struct node));
    struct node* two = malloc(sizeof(struct node));
    struct node* three = malloc(sizeof(struct node));
    
    
    head->data = 5;
    head->next = two;
    
    two->data = 3;
    two->next = three;
    
    three->data = 2;
    three->next = NULL; 
    
    return head;
}

void lenthTest()
{
    struct node* test = buildList();
    int len ;
    len = lenth(test);
    printf("%d \n",len);
    
}
int lenth(struct node* head)
{
    struct node* current = head;
    int count = 0 ;
    while (current != NULL)
    {
        count++;
        current = current -> next ;
    }

    return count ;
}
