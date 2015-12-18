#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef  struct node
{
	int item ;
	struct node * next ;
}Node; 

typedef struct list
{
	Node * Head ;
	Node * Tail ;
	int length ;
}List ;

void init(List * l)
{
	l->Head = NULL ;
	l->Tail = NULL ;
	l->length = 0 ;
}

void print_list(List * l)
{
	if(l->length == 0)
		printf("List is empty \n");
	else
	{
		Node * temp = l->Head ;
		printf("element in the list :\n");
		while(temp)
		{
			printf("%d\t",temp->item);
			temp = temp->next ;
		}
		printf("\n");
	}
}
Node * newNode(int element)
{
	Node * newNode = (Node *)malloc(sizeof(Node));
	newNode->item = element ;
	newNode->next = NULL ;
	return newNode ;
}
void push (List * l ,Node * newNode )
{
	if(l->Head == NULL )
	{
		l->Tail = l->Head = newNode ;
		newNode->next = NULL ;
		l->length += 1 ;
	}
	else
	{
		newNode->next = l->Head ;
		l->Head = newNode ;
		l->length += 1 ;
	}
}
void insert_element(List * l , Node * newNode )
{
	if(l->Head == NULL )
	{
		push(l,newNode);
	}
	else
	{
		l->Tail->next  = newNode ;
		l->Tail = l->Tail->next ;
		l->Tail->next = NULL ;
		l->length += 1 ;
	}
}

void remove_element(List * l , int element )
{
	bool flag = false ;
	if(l->length == 0 )
		printf("List is empty \n");
	else  
	{
		if(l->length == 1 && l->Head->item == element)
		{

			l->Head = l->Tail = NULL ;
			l->length -=1;
			flag = true ;
		}
		else
		{
			Node * temp = l->Head ;

			if(l->Head->item == element)
			{
				l->Head = l->Head->next ;
				l->length -= 1 ;
			}
		else{

			while(temp->next != NULL && temp->next->item != element )
				temp = temp->next ;
			if(temp->next != NULL)
			{
				if(l->Tail == temp->next)
					l->Tail = temp ;
				temp->next = temp->next->next ;
				l->length -= 1 ;
			}

		} }

	}
}
int kthlast(Node * node , int element)
{
	if(node == NULL)
		return 1 ;
	else
	{
		int i = kthlast(node->next,element);
		if(i == element)
			printf("\n%d\n",node->item);
		return i+1 ;
	}
}
int  print_length(Node * head)
{
	int i = 0 ;
	while(head)
	{
		i++ ;
		head = head->next ;
	}
	return i  ;
}

int GetNth(List * l  , int nth)
{
	if(nth >= l->length || nth < 0)
		return  -1;

	Node * temp  = l->Head  ;
	int i = 0 ;
	while(temp)
	{
		if( i == nth)
			return temp->item  ;
		temp = temp->next ;
		i++ ;
	}
	
}
void freeList(List * l )
{
	Node * current = l->Head ;
	Node * temp ;
	while(current)
	{
		temp = current->next ;
		free(current);
		current = temp ;
	}
	l->Head = NULL ;
}
void pop(List * l)
{
	if(l->Head == NULL)
		printf("list is empty\n");
	else
	{
		l->Head = l->Head->next ;
		l->length -= 1 ;
		if(l->length == 0 )
			l->Tail = NULL ;
	}
}
void insert_Nth(List * l ,int element, int location )
{
	if(location > l->length || location < 0)
		printf("Index out of bounds \n");
	else
	{
		if(location == 0)
			push(l,newNode(element));
		else if(location == l->length)
			insert_element(l,newNode(element));
		else
		{
			int count = location -1 ;
			Node * temp = l->Head ;
			while(count)
			{
				temp = temp->next ;
				count-- ;
			}
			Node * newnode = newNode(element);
			newnode->next = temp->next ;
			temp->next = newnode ;
			l->length += 1;
		}

	}
}
void  split_list(List * l , List * l1 , List * l2 )
{
	if(l->Head == NULL )
	{
		init(l1);
		init(l2);
	}

	else if(l->Head->next == NULL )
	{
			insert_element(l1,newNode(l->Head->item));
	}
	else if(l->Head->next->next == NULL)
	{
		insert_element(l1,newNode(l->Head->item));
		insert_element(l2,newNode(l->Head->next->item));
	}
	else {
	Node * slow , * fast , * temp ;
	temp = slow = fast = l->Head ;
	while((fast->next != NULL) && (fast->next->next != NULL))
	{
		slow = slow->next ;
		fast = fast->next->next ;
	}

	 while(temp != slow->next)
	 {
	 	insert_element(l1,newNode(temp->item));
	 	temp = temp->next ;
	 }
	 while(temp)
	 {
	 	insert_element(l2,newNode(temp->item));
	 	temp = temp->next ;
	 }
	}
}
void append(List * l1 , List * l2 )
{
	if(l1->Head == NULL)
	{
		l1->Head = l2->Head ;
		l1->length = l2->length ;
	}
	else
	{
		l1->Tail->next = l2->Head ;
		l1->length += l2->length ;
		init(l2);
	}
}
void sorted_insert(Node ** Head , Node * newNode )
{
	if(*Head == NULL||(*Head)->item > newNode->item)
	{
		newNode->next = *Head ;
		*Head = newNode ;

	}
	else
	{
		Node * current = *Head ;
		while(current->next != NULL && current->next->item < newNode->item)
			current = current->next ;
		newNode->next = current->next;
		current->next = newNode ;
	}
}
void Insertion_Sort(List * l)
{
	Node * next , * result = NULL,* current =  l->Head ;

	while(current)
	{
		next = current->next ;
		sorted_insert(&result,current);
		current = next ;
	}

	l->Head = result ;
	
}
void remove_duplicates(List * l)
{
	Node * temp , * current = l->Head ;
	if(current)
	while(current->next != NULL)
	{
		if(current->item == current->next->item)
		{
			if(current->next == l->Tail)
				l->Tail = current ;
			 temp = current->next  ;
			 current->next = temp->next ;
			 free(temp);
			l->length -= 1 ;

		}
		if(current->next != NULL && current->item != current->next->item)
		current = current->next ;
	}


	

}
void move_node(List * destination,List *  source )
{
	if(source->Head != NULL)
	{
		Node * temp = source->Head ;
		pop(source);
		push(destination,temp);
	}
}

void alternative_split(List * l , List * l1 , List * l2)
{
	if(l->Head)
	{
		Node * temp = l->Head , * fir ,* sec;
		while(temp && temp->next)
		{
			fir = temp ;
			sec = temp->next ;
			temp = temp->next->next ;
			insert_element(l1,fir);
			insert_element(l2,sec);
			
		}
		if(temp)
			insert_element(l1,temp);
		
	}
}

void suffle_merge(List * l , List * l1 , List * l2) 
{
	if(l1->Head && l2->Head)
	{
		l->Head = l1->Head  ;
		Node * fir , * sec ;
		while(l1->Head && l2->Head)
		{
			fir = l1->Head->next ;
			sec = l2->Head->next ;
			l1->Head->next = l2->Head ;
			l2->Head->next = fir ;
			l1->Head = fir ;
			l2->Head = sec ;


		}
		if(l2->Head)
		{
			append(l,l2);
		}
		init(l1);
		init(l2);
	}
	if(l1->Head)
	{
		l->Head = l1->Head ;
		l->length = l1->length ;
	}
	else
	{
		l->Head = l2->Head ;
		l->length = l2->length ;
	}
}
void sorted_merge(List * l,List * l1 , List * l2)
{
	if(l1->Head && l2->Head)
	{
		(l1->Head->item < l2->Head->item) ? (l->Head = l1->Head ):(l->Head = l2->Head );
		Node * temp ;
		while(l1->Head && l2->Head)
		{
			if(l1->Head->item < l2->Head->item)
			{ 
				while(l1->Head->next != NULL && l1->Head->next->item < l2->Head->item)
					l1->Head = l1->Head->next ;

				temp = l1->Head->next ;
				l1->Head->next = l2->Head ;
				l1->Head = temp ;
			}
			else
			{
				while(l2->Head->next != NULL && l2->Head->next->item < l1->Head->item)
					l2->Head = l2->Head->next ;
				temp = l2->Head->next ;
				l2->Head->next = l1->Head ;
				l2->Head = temp ;
			}

		}


	}
	else if(l1->Head)
		l->Head = l1->Head ;
	else if(l1->Head)
		l->Head = l2->Head ;
	init(l1);
	init(l2);
}
int main()
{

	List l, l1 ,l2 ;
	init(&l);
	int element ;
	int choice ;
	while(true)
	{

		printf("Select one of the option below :\n\t\t1.Insert\n\t\t2.Remove\n\t\t3.Disply\n\t\t4.Last-Kth element\n\t\t5.List Lenght\n\t\t");
		printf("6.Get 'N'th element\n\t\t7.Pop\n\t\t8.Push\n\t\t9.Insert Nth location \n\t\t10.Split list by half\n\t\t11.Append\n\t\t12.SortList");
		printf("\n\t\t13.Remove Duplicates\n\t\t14.Move Node from one list to anoter\n\t\t15.alternative splits\n\t\t16.Suffle merge\n\t\t17.Sorted merge\n\t\t18.EXit\n\n");
		scanf("%d",&choice);
		switch(choice)
		{
				
			case 1 :	printf("Enter an element to insert into list \n");
						scanf("%d",&element);
						insert_element(&l,newNode(element));
						break ;
			case 2:		printf("Enter an element to remove \n" );
						scanf("%d",&element);
						remove_element(&l,element);
						break ;
			case 3 :	print_list(&l);
						break ;
			case 4 :	printf("enter a number to check last k-th item in list\n");
						scanf("%d",&element);
						kthlast(l.Head,element);
						break ;

			case 5:		((element = print_length(l.Head)) == 0 ) ? printf("list is empty\n") : printf("length of list is %d\n",element );
						break ;


			case 6:		printf("enter element number to get item \n");
						scanf("%d",&element);
						choice = GetNth(&l,element);
						if(choice != -1)
							printf("element %d located in index %d\n",choice,element);
						else 
							printf("index out of bounds \n");
						break ;

			case 7:		pop(&l);
						break ;

			case 8:		printf("Enter an element to Push \n"); 
						scanf("%d",&element);
						push(&l,newNode(element));
						break ;

			case 9:		printf("Enter element to insert \n");
						scanf("%d",&element);
						printf("Enter location to be insert \n");
						scanf("%d",&choice);
						insert_Nth(&l,element,choice);
						break ;

			case 10:	init(&l1);
						init(&l2);
						split_list(&l,&l1,&l2);
						print_list(&l1);
						print_list(&l2);
						freeList(&l1);
						freeList(&l2);
						break ;

			case 11 : 	init(&l1);
						init(&l2);
						split_list(&l,&l1,&l2);
						print_list(&l1);
						print_list(&l2);
						printf("Appending above two lists \n");
						append(&l1,&l2);
						print_list(&l1);
						print_list(&l2);
						freeList(&l1);
						freeList(&l2);
						break ;
			case 12 : 	Insertion_Sort(&l);
						print_list(&l);
						break ;
			case 13 :	Insertion_Sort(&l);
						remove_duplicates(&l); 	
						print_list(&l);
						break ;
			case 14 :	init(&l1);
						init(&l2);
						split_list(&l,&l1,&l2);
						printf("before lists \n");
						print_list(&l1);
						print_list(&l2);
						move_node(&l1,&l2);
						printf("after move node operation \n");
						print_list(&l1);
						print_list(&l2);
						freeList(&l1);
						freeList(&l2);
						break ;

			case 15 :	init(&l1);
						init(&l2);
						alternative_split(&l,&l1,&l2);
						Insertion_Sort(&l2);
						Insertion_Sort(&l1);
						print_list(&l1);
						print_list(&l2);
						sorted_merge(&l,&l1,&l2);
						print_list(&l1);
						freeList(&l1);
						freeList(&l2);
						init(&l);
						break ;


			case 16 :	init(&l1);
						init(&l2);
						alternative_split(&l,&l1,&l2);
						printf("Two lists :\n");
						print_list(&l1);
						print_list(&l2);
						suffle_merge(&l,&l1,&l2);
						print_list(&l1);
						print_list(&l2);
						printf("after suffle merge \n");
						print_list(&l);
						break ;

			case 17 :	init(&l1);
						init(&l2);
						alternative_split(&l,&l1,&l2);
						printf("Two lists :\n");
						print_list(&l1);
						print_list(&l2);
						sorted_merge(&l,&l1,&l2);
						print_list(&l1);
						print_list(&l2);
						printf("after suffle merge \n");
						print_list(&l);
						break ;



			case 18	:	printf("Good bye\n");
						freeList(&l);
						return 0 ;
			default : 	printf("Please select proper input \n");
		}
	}

}