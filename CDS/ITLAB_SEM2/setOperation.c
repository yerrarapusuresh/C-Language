/*****************************************************************************************************************************************************************************
*
*AUTHOR :YERRARAPU SURESH 
*DICRIPTION : BINARY OPERATION(UNION , INTERSCETION , DIFFERENCE , SYMMETRIC DIFFERENCE ) ON SETS 


*/





#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000 


typedef int setType ;

typedef struct set
{
	setType array[MAX];
	int position ;
}Set;
void set_init(Set * s)
{
	s->position = 0 ;
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void setSort(Set * a , Set * b)
{
	qsort(a->array,a->position,sizeof(int),cmpfunc);
	qsort(b->array,b->position,sizeof(int),cmpfunc);
}





void setDisply(Set * s)
{
	int i ;
	printf("\n{\t");
	for(i = 0 ; i < s->position ;i++)
		printf("%d\t",s->array[i]);
	printf("}\n");
}
void setUnion(Set * a , Set * b , Set * u)
{
	
	int i,*res,j;
	setSort(a,b);
	
	for( i = 0 ; i < (a->position ) ; i++)
	{
		u->array [i] = a->array[i];
		u->position++ ;
		
	}
	for(i = 0 ;i < b->position ; i ++)
	{
		j = b->array[i];
		res = bsearch(&j,a->array,a->position,sizeof(int),cmpfunc);
		if(!res)
		{
			u->array[u->position++] = b->array[i];
		}
	}
	qsort(u->array,u->position,sizeof(int),cmpfunc);


}
void setIntersect(Set * a , Set * b , Set * in)
{
	int i ,j, * res ;
	setSort(a,b);
	if(a->position > b->position)
	{
	for(i = 0 ; i <a->position ; i++)
	{	
			j = a->array[i];
			res = bsearch(&j,b->array,b->position,sizeof(int),cmpfunc);
			if(res)
			{
				in->array[in->position++] = j ;
			}
	}
}
else
{
	for(i = 0 ; i <b->position ; i++)
	{	
			j = b->array[i];
			res = bsearch(&j,a->array,a->position,sizeof(int),cmpfunc);
			if(res)
			{
				in->array[in->position++] = j ;
			}
	}
}
	qsort(in->array,in->position,sizeof(int),cmpfunc);
}
void setDiff(Set * a, Set * b,Set * di)
{
	setSort(a,b);
	int i ,j,*res;
	for(i = 0 ; i <a->position ; i++)
	{	
			j = a->array[i];
			res = bsearch(&j,b->array,b->position,sizeof(int),cmpfunc);
			if(!res)
			{
				di->array[di->position++] = j ;
			}
	}


}
void setSymmDiff(Set * a , Set *b,Set * in)
{
	int i ,j, * res ;
    setSort(a,b);
	
	
	for(i = 0 ; i <a->position ; i++)
	{	
			j = a->array[i];
			res = bsearch(&j,b->array,b->position,sizeof(int),cmpfunc);
			if(!res)
			{
				in->array[in->position++] = j ;
			}
	}


	for(i = 0 ; i <b->position ; i++)
	{	
			j = b->array[i];
			res = bsearch(&j,a->array,a->position,sizeof(int),cmpfunc);
			if(!res)
			{
				in->array[in->position++] = j ;
			}
	}

	qsort(in->array,in->position,sizeof(int),cmpfunc);

}
int main()
{
	int limit,i;
	Set A,B,C;
	set_init(&A);
	set_init(&B);

	printf("How many elements would you like to enter in SET A:\t");
	scanf("%d",&limit);
	for(i = 0 ; i < limit ;i++)
	{
		printf("\nenter element number %d in SET A :\t",i);
		scanf("%d",&(A.array[A.position++]));

	}
	printf("How many elements would you like to enter in SET B:\t");
	scanf("%d",&limit);
	for(i = 0 ; i < limit ;i++)
	{
		printf("\nenter element number %d in SET B :\t",i);
		scanf("%d",&(B.array[B.position++]));
	}
	while(true)
	{
		printf("enter you option:\n\t1.union\n\t2.intersection\n\t3.set difference\n\t4.set symmetric difference\n\t5.exit\n\t");
		scanf("%d",&limit);
		switch(limit)
		{
			case 1 :set_init(&C);
					setUnion(&A,&B,&C);
					printf("\nunion of SET A and SET B is :");
					setDisply(&C);
					break ;
			case 2 :set_init(&C);
					setIntersect(&A,&B,&C);
					printf("\nintersection of SET A and SET B is :");
					setDisply(&C);
					break ; 
			case 3 :set_init(&C);
					setDiff(&A,&B,&C);
					printf("\ndiff. of SET A and SET B is :");
					setDisply(&C);
					break ; 
			case 4 : set_init(&C);
					setSymmDiff(&A,&B,&C);
					printf("\nSymmetic diff. of SET A and SET B is :");
					setDisply(&C);
					break ;
			case 5 : 
					return 0 ;
					break ;
			default :
					printf("Please enter any number between 1-5\n");
		}
	}



}