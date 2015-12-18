
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node 
{
	int data;
	bool isred;
	struct node * left;
	struct node * right;
}Node;

Node * newNode(int key)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->data = key;
	newNode->right = newNode->left = NULL;
	newNode->isred = true;
}

bool isRed(Node * root)
{
	if(root == NULL)
		return false;
	return root->isred == true;
}

Node * rotateLeft(Node * h)
{
	Node * x = h->right;
	h->right = x->left;
	x->left = h;
	x->isred =  h->isred;
	h->isred = true;
	return x;
}

Node * rotateRight(Node *h)
{
	Node * x = h->left;
	h->left = x->right;
	x->right = h;
	x->isred = h->isred;
	h->isred = true;
	return x;
	
}

void flipColors(Node *h)
{
	h->left->isred = h->right->isred = false;
	h->isred = true;
}

Node * insert(Node * root, int key)
{
	if(root == NULL)
		return newNode(key);
	if(root->data > key)
		root->left = insert(root->left, key);
	else if(root->data < key)
		root->right = insert(root->right, key);
	else
		root->data = key;
	if(isRed(root->right) && !isRed(root->left))
		root = rotateLeft(root);
	else if(isRed(root->left) && isRed(root->left->left))
		root = rotateRight(root);
	else if(isRed(root->right) && isRed(root->left))
		flipColors(root);
	return root;
}

int height(Node * root)
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

void inorder(Node * root)
{
	if(root == NULL)
		return ;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int size = sizeof(array)/sizeof(array[0]);
	int i ;
	Node * root = NULL;
	for(i = 0; i < size; i++)
		root = insert(root, array[i]);
	inorder(root);
	printf("\n%d\n", height(root));

}