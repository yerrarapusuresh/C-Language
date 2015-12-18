#include <stdio.h>
#include <stdlib.h>

struct node 
    {
        int data ;
        struct node* next ;
        
    } ;
struct node * root = NULL;

struct node * buildList() ;
int lenth();
void lenthTest();
void PushTest();
void Push(int data);
void Pop();
int main()
{
    PushTest();
    lenthTest();
    int i ;
    for(i = 0; i <20; i ++)
    Pop();
    
    lenthTest();
    PushTest();
    lenthTest();
}

struct node * buildList()
{   
    struct node * head = root;
    
    
    return head ;  
    
    
}   

void lenthTest()
{
    //struct node * head = buildList();
    int len = lenth();
    printf("lenth = %d \n",len);
}

int lenth()
 {
    struct node * current = root;
    int count = 0 ;
    while (current != NULL) 
    {
        count ++ ;
        printf("%d",current -> data);
        current = current -> next ;
    }
 
    return count ;
 }
 
 void Push( int data)
 {
    struct node* newnode = malloc(sizeof(struct node));
    
    if(root == NULL)
    {
        newnode -> data  = data;
        newnode -> next = NULL; 
        root = newnode;
    }
    else
    {
    newnode -> data = data;
    newnode -> next = root ;
    root = newnode ;
    
    
  
  }
    
 
 }
 
 void PushTest()
 {
    //struct node * head = buildList();
    
    int i = 0;
    for(i = 10 ; i >=0; i-- )
    {
        Push(i);
 }
 }
void Pop()
{   
    if(root != NULL)
    {
    struct node* temp = root ;
    
    printf("free element is \t%d\n",temp ->data);
    root = root -> next ;
    free(temp);
    }
    else
        printf("nothing to delete here \n");
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
