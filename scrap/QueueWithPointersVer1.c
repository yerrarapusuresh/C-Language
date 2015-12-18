#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data ;
    struct node * next ;
} ;

struct node *head = NULL ;

void Append(int data);
void ShowList();

int main()
{
    int number ;
    while (true)
    {
        printf("Enter your option \n\t1.Append \n\t2.Remove \n\t3.ShowList \n\t4.Exit \n");
        scanf("%d",&number);
        
        switch(number)
        {
            case 1 : printf("Enter any element to append \n");
                     scanf("%d",&number);
                     Append(number);
                     break ;
            case 2 : 
                     break;
            case 3 : ShowList();
                     break;
            case 4 :
                     return 0;
                     break ;
            default : printf("Please enter proper option \n"); 
        }
    }    
}

void Append(int data)
{
    struct node * newNode = malloc(sizeof(struct node ));
    struct node * temp = head ;
    
    newNode -> data = data ;
    newNode -> next = NULL;  
    if(head == NULL)
    {
        head = newNode ;
             
    }
    else
    {
    
        while(temp)
        {
            temp = temp -> next ;
        }
        temp -> next = newNode;
    }
}

void ShowList()
{
    struct node * temp = head ;
    while(temp != NULL)
    {
        printf("\t%d\n",temp -> data);
    }
}
