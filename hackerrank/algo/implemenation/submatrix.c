#include <stdio.h>
#include <stdlib.h>
void printArray(char*  array[], int r , int c)
{
	int i,j;
	for( i = 0 ; i < r ;i++)
	{
		for(j = 0 ;j < c ;j++)
			printf("%c",array[i][j]);
		printf("\n");
	}
}
int checker(char * array[] , char * subarray[],int is,int js ,int iend,int jend)
{
	int i , j,ii = 0 , jj = 0  ;
	for( i = is ; i < is+iend ; i++,ii++)
		for(j = js,jj=0 ; j < js+jend ;j++,jj++)
			if(array[i][j] != subarray[ii][jj])
			{
				//printf("%c \n",subarray[ii][jj]);//,subarray[ii][jj]);
				return 0 ;
			}
	return 1 ;
}

int main()
{
	int size ;
	scanf("%d",&size);
	while(size--)
	{

		int row , col , i , c,j;
		scanf("%d %d",&row,&col);
		char * array[row];
		for( i = 0 ; i < row ;i++)
			array[i] = (char * )malloc(sizeof(char)*col);
		for(i = 0 ; i < row;i++)
			for(j = 0 ; j < col ; )
				{
					c = getchar();
					if(c != '\n')
						array[i][j++] = c ;
				}
		



int r , cc;
		scanf("%d %d",&r,&cc);
		char* subarray[r];
		for(i = 0 ; i < r ;i++)
			subarray[i] = (char *)malloc(sizeof(char)*cc);
		for(i = 0 ; i < r;i++)
			for(j = 0 ; j < cc ; )
				{
					c = getchar();
					if(c != '\n')
						subarray[i][j++] = c ;
				}
		if(!(r > 0 && r <= row && c > 0 &&  cc<= c))
		{
			printf("NO");
			return 0 ;
		}
int res = 0 ;
		for( i = 0 ; i <= (row - r) && !res;i++)
			for(j = 0 ; j <= (col-cc) && !res;j++)
			{
				if(array[i][j] == subarray[0][0])
				{
					//printf("going to checker %c %c\n",array[i][j],subarray[0][0]);
					res = checker(array,subarray,i,j,r,cc) ;
						
				}
			}
        if(res)
            printf("YES\n");
        else
		printf("NO\n");


	}
}