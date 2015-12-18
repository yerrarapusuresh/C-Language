#include <stdio.h>
#include <stdbool.h>
#include "trees.h"

int main()
{
	TreeNode * root = NULL ;

	int input ;

	while(true)
	{
		printf("Enter your choice\n\t\t1.Insert\n\t\t2.Disply\n\t\t3.Exit\n\n");
		scanf("%d",&input);
		switch(input)
		{
			case 1 : printf("enter your element to insert:\n");
					 scanf("%d",&input);
					 root = InsertTree(root,NewNode(input));
					 break ;
			case 2 :if(root == NULL)
						printf("no elements in the list\n");
					else
						InorderPrint(root);
					break;
			case 3 :
						return 0 ;
					break;
			default : printf("Enter proper input\n");
						break;



		}
	}
}