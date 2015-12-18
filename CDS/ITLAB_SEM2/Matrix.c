/* Student Id's: 
14MCMT35 SHASHIKANTH ILEGER
14MCMT43 YERRARAPU SURESH
14MCMT54 MUNI SHIVE PRASAD

 This program takes no of nodes and adjacency matrix  and path length as input
 It will give output matrix where each entry specifies  no of paths between vetexes of path length what user gave as input
 for any given input for source and destination vertex it gives number of paths between them
*/

#include <stdio.h>
#include <stdlib.h>

int n ;
void copyArray(int a[][n],int b[][n],int dim)
{
	int i , j ;
	for(i = 0 ; i < dim ; i++)
		for(j = 0 ; j < dim ;j++)
			a[i][j] = b[i][j];

}


void printArray(int  a[][n],int dim)
{
	int i , j ;
	
	for(i = 0 ; i < dim ; i++)
	{
		for(j = 0 ; j < dim ;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
		
}
void matMul(int  a[][n],int  temp[][n],int dim)
{
	int i , j ,k,val = 0;
	for(i = 0 ; i < dim ; i++)
		for(j = 0 ; j < dim ;j++)
		{
			for(k = 0 ; k < dim;  k++)
			{
				val += a[i][k]*a[k][j];
			}
			temp[i][j] = val ;
			val = 0 ;
		}
			
}
void matMul2(int  a[][n],int  temp[][n],int res[][n],int dim)
{
	int i , j ,k,val = 0;
	for(i = 0 ; i < dim ; i++)
		for(j = 0 ; j < dim ;j++)
		{
			for(k = 0 ; k < dim ;  k++)
			{
				val += a[i][k]*temp[k][j];
			}
			res[i][j] = val ;
			val = 0 ;
		}
			
}


void nullArray(int a[][n],int dim)
{
		int i , j ;
	for(i = 0 ; i < dim ; i++)
		for(j = 0 ; j < dim ;j++)
			a[i][j] = 0;
}



int main()
{
	int numNodes = 0 ;
	printf("please enter number of nodes of graph");
	scanf("%d",&numNodes);

	int mart[numNodes][numNodes];
	int temp[numNodes][numNodes];
	int res[numNodes][numNodes];
	int i,j ;

	printf("please enter %d number inputs :",numNodes*numNodes);
	for(i = 0 ; i < numNodes ; i++)
	{
		for(j = 0 ; j <numNodes ;j++)
		{
		scanf("%d",&mart[i][j]);
		printf("\t");
		}
		printf("\n");
	}
	n = numNodes ;
	int plen = 0 ;
	printf("enter the path lengh \n");
	scanf("%d",&plen);

for( i = 0 ; i < plen-1 ; i++)
{
	if( i == 0)
	{
		copyArray(temp,mart,numNodes);
		matMul2(temp,mart,res,numNodes);
	}
	else
	{
		copyArray(temp,res,numNodes);
		nullArray(res,numNodes);
		matMul2(mart,temp,res,numNodes);
	}
}

printArray(res,numNodes);
int x , y ;
printf("enter source and destination vertex(0 to maxnode-1) to find number of paths of %d lengh\n",plen);
scanf("%d %d",&x,&y);
( x < numNodes && y <numNodes)? (printf("there are %d paths from %d to %d\n",res[x][y],x , y)):(printf("ERROR!! :invalid verteces\n"));

		
}