#include<stdio.h>
#include<stdlib.h>
//#include<stdbool.h>
typedef struct Node
{
	int key;
//	int count;
	int isRed;
	struct Node *left;
	struct Node *right;
}node;

node *newnode(int value)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->key = value;
	temp->isRed = 1;
	temp->left = temp->right = NULL;
	return temp;
}

node *RotateLeft(node * x)
{
	node * h = x->right;
	x->right = h->left;
	h->left = x;
	h->isRed = x->isRed;
	x->isRed = 1;
	return h;
}

node *RotateRight(node * x)
{
	node * h = x->left;
	x->left = h->right;
	h->right=x;
	h->isRed = x->isRed;
	x->isRed = 1;
	return h;
}

void flipcolor(node *x)
{
	x->right->isRed = x->left->isRed = 0;
	x->isRed = 1;	
}

int isred(node * root)
{
	if(root == NULL)
		return 0;
	return root->isRed == 1;	
}

node *insert(node *root,int value)
{
	if(root == NULL)
		return newnode(value);		
	if(value < root->key)
		root->left = insert(root->left,value);
	else if(value > root->key)
		root->right = insert(root->right,value);
	else
		root->key = value;		
	if(isred(root->right) && !isred(root->left))
			root = RotateLeft(root);
	else if(isred(root->left) && isred(root->left->left))
		root = RotateRight(root);		
	else if((isred(root->left)) && (isred(root->right)))
 		flipcolor(root);
	return root;
}
node inorder(node *root)
{
	if(root == NULL)
		return;
	else
		inorder(root->left);
		printf("%d\n",root->key);
		inorder(root->right);
}

int height(node * root)
{
	if(root == NULL)
		return 0;
	int right = height(root->right);
	int left = height(root->left);
	int max;
	if(right > left)
		 max = right;
	else
		max = left;
	return max + 1;
}

int main()
{
	node * root = NULL;
	int array[]= {1,2,3};
	int i;
	//root = insert(root, 1);
	//root = insert(root, 2);
	
	for(i = 0;i < (sizeof(array)/sizeof(array[0]));i++)
	{
		root = insert(root, array[i]);
		//("%d\n",array[i] );
	}
	inorder(root);
	printf("heit%d\n",height(root) );
}