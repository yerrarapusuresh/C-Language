#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node 
{   
    int data ;
    struct node * next ;
} ;

struct node * head = NULL ;

void Push(int Input);
void Pop();
void ShowList();
void MemFree();

int main()
{
    int number ;
    while(true)
    {
        printf("Enter your option \n \t1.Push \n\t2.Pop \n\t3.ShowList \n\t4.Exit \n");
        scanf("%d",&number);
        
        switch(number)
        {
            case 1 : printf("Enter a number to push onto stack \n");
                     scanf("%d",&number);
                     Push(number);
                     break;
                     
            case 2 : Pop();
                     break ;
            case 3 :ShowList();
                     break ;
            case 4 : MemFree();
                     return 0 ;
                     break ; 
            default :printf("Enter a proper choice \n");
                    
        }
        
    }
}

void Push(int Input)
{
    struct node * newNode = malloc(sizeof(struct node));
    
    newNode -> data = Input ;
    if(head == NULL)
    {
            head = newNode ;
    }
    else
    {
        newNode -> next = head ;
        head = newNode ;
    }
}

void Pop()
{
    struct node *temp = head ;
    if(temp == NULL)
    {
        printf("Stack is empty \n");
        
    }
    else
    {
    
    head = head -> next ;
    printf("Popped element is %d\n",temp -> data);
    free(temp);
    }
}
void ShowList()
{
    struct node * temp = head ;
    int count =  0;
    while(temp != NULL)
    {
        printf("\t%d\n",temp -> data ) ;
        count ++ ;
        temp = temp -> next ;
    }
    printf("Total elements in the stack is %d \n",count);
}
void MemFree()
{
    struct node * temp  ;
    
    while(head  != NULL)
    {
        temp = head ;
        head = head -> next ;
        free(temp);
              
    }
    
      
}

