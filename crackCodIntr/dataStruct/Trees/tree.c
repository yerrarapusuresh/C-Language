#include "trees.h"
#include <stdlib.h>
#include <stdio.h>

TreeNode * NewNode(int data)
{
	TreeNode * newnode = malloc(sizeof(TreeNode));
	newnode->data = data ;
	newnode->right = NULL ;
	newnode->left = NULL ;
	return newnode ;
}

TreeNode * InsertTree(TreeNode * root , TreeNode * NewNode)
{
	if(root == NULL)
	{
		return NewNode ;
	}
	else
	{
		if(root->data > NewNode->data)
			root->left = InsertTree(root->left,NewNode);
		else
			root->right = InsertTree(root->right,NewNode);
		return root ;
	}
}

void InorderPrint(TreeNode * root)
{
	if(root)
	{
		InorderPrint(root->left);
		printf("%d\n",root->data );
		InorderPrint(root->right);
	}
}

