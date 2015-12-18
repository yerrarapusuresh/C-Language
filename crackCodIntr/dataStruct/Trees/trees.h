typedef struct node
{

	struct node * left ;
	int data ;
	struct node * right ;
	
}TreeNode;

TreeNode * NewNode(int data );
TreeNode * InsertTree(TreeNode *  , TreeNode *);
void InorderPrint(TreeNode * root);

