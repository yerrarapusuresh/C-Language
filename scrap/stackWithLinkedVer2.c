#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data ;
    struct node* next ;
};

struct node * BuildList();
struct node * appendTest( );
struct node *append(struct node ** headRef, int data);
void length();

int main()
{   
    
    length();
}

struct node * BuildList()
{
    struct node * head = NULL;
    
    return head ;
}

struct node * appendTest( )
{
    struct node* head = BuildList();
    struct node* upDated = append(&head,33);
    upDated = append(&head,2);
     upDated = append(&head,1);
    return upDated;
}

struct node *append(struct node ** headRef, int data)
{
    struct node * newNode = malloc(sizeof(struct node ));
    newNode -> data = data ;
    if(*headRef  != NULL)
    {
        *headRef = newNode;
    }
    else
    {
        newNode -> next = *headRef ;
        *headRef = newNode ;
    }
    
    return *headRef ;
}

void length()
{
        int count = 0  ;
        struct node * head = appendTest();
        while(head != NULL)
            {
                count ++;
                head = head -> next ;
            }    
        printf("%d",count);
}










