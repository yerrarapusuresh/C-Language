#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
	char name[20];
	int x ;
	int y ;
	struct node * left ;
	struct node * right ;
	
}Node;

Node * insert(Node * node ,char  name[] , int x , int y , bool flag) ;
Node * newNode(char name[],int x,int y);
void disply(Node * node);
Node * insertStr(Node * node , char name[],int x ,int y );
void searchByDist(Node * node , int dist);

//Node *root=NULL;
//Node * root2 = NULL ;
int main()
{
	FILE *fp ;
	char buff[20];
	int x , y ;
        bool flag = true ;
	Node * root = NULL ;	
	Node * root2 = NULL ;
	if( (fp = fopen("input.txt","r")) == NULL)
	{
		printf("File could not opend ! \n");
		return -1 ;
	}
	printf("Elements in the File \n");
	while((fscanf(fp,"%s %d %d",buff,&x,&y)) != EOF)
	{
		root = insert(root,buff,x,y,flag);
		root2 = insertStr(root2,buff,x,y);
		printf("%s %d %d\n",buff,x,y);
	}
	printf("elements in Tree by X and Y origons \n");
	disply(root);
	printf("elements in tree by name \n");
	disply(root2);

	fclose(fp);
}

Node * insert (Node * node , char  name[],int x , int y ,bool flag )
{
	if( node == NULL)
	
		return newNode(name,x,y);
	else 
	{
		
		if(flag )
		{
			
			if(x  <= node->x)
				node->left = insert(node->left,name,x,y,false );
			else
				node->right = insert(node->right,name,x,y,false);
		}
		else
		{
	
			if (y <= node-> y)
				node -> left = insert(node->left,name,x,y,true);
			else
				node -> right = insert(node->right,name,x,y,true);
		}
	}
		return node ;
}

Node * newNode(char name[],int x , int y )
{
	Node * newNode =(Node *) malloc(sizeof(Node));
	strcpy(newNode->name , name);
	newNode->x = x ;
	newNode->y = y ;
	newNode -> left = NULL ;
	newNode -> right = NULL ;
	return newNode ;
	
}

void disply(Node * node)
{
	if(node == NULL)
		return ;

	
		disply(node->left);
		printf("%s %d %d \n",node->name,node->x,node->y);
		disply(node->right);
	
}


Node * insertStr(Node * node , char  name[] , int x , int y)
{
	if(node == NULL)
		return newNode(name,x,y);
	else
	{
		if(strcmp(name,node->name)<= 0)		
			node->left = insertStr(node->left,name,x,y);
		else
			node->right = insertStr(node->right,name,x,y);
	}
	return node ;
}







