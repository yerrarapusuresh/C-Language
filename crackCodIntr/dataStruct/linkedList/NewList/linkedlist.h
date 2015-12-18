typedef struct node 
{
	int data ;
	struct node * next ;
}Node ;

void listReverse(Node ** head);
void push(Node ** head , Node * newnode);
void printList(Node * head);
Node * newNode(int data);