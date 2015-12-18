#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int i,j[] = {7,6,5,4,3,2,1,0};
	int k = 50 ;
	int *res;
	qsort(j,8,sizeof(int),cmpfunc);
	for(i = 0 ; i <8;i++)
		printf("%d\t",j[i]);
	i = 4 ;
	res = bsearch(&i,j,8,sizeof(int),cmpfunc);
	if(res)
		printf("success\n");
	else printf("fail\n");
	res = bsearch(&k,j,8,sizeof(int),cmpfunc);
	if(res)
		printf("success\n");
	else printf("fail\n");
	
	printf("\n");

}