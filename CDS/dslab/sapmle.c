#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char name[20];
	int x ;
	int y ;
	struct node * left ;
	struct node * right ;
	
}Node;

Node * insert(Node * node ,char  name[] , int x , int y , int level) ;
Node * newNode(char name[],int x,int y);
void disply(Node * node);

Node *root=NULL;
int main()
{
	FILE *fp ;
	char buff[20];
	int x , y ;
        int level=1;
	if( (fp = fopen("input.txt","r")) == NULL)
	{
		printf("File could not opend ! \n");
		return -1 ;
	}
	
	while((fscanf(fp,"%s %d %d",buff,&x,&y)) != EOF)
		root = insert(root,buff,x,y,level++);
	disply(root);
	fclose(fp);
}

Node * insert (Node * node , char  name[],int x , int y ,int level )
{
	if( node == NULL)
	
		return newNode(name,x,y);
	else 
	{
		
		if(level % 2 == 0 )
		{
			//printf("level even\n");
			if(node->x  <= x)
				node->left = insert(node->left,name,x,y,level );
			else
				node->right = insert(node->right,name,x,y,level);
		}
		else
		{
			//printf("level odd\n");
			if (node-> y <=  y)
				node -> left = insert(node->left,name,x,y,level);
			else
				node -> right = insert(node->right,name,x,y,level);
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
	if(node != NULL)
	{
		disply(node->left);
		printf("%s %d %d \n",node->name,node->x,node->y);
		disply(node->right);
	}
}






