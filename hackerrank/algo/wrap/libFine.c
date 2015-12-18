#include <stdio.h>

int main()
{
	typedef struct date
	{
		int day ;
		int month  ;
		int year ;
	}Date;

	Date e , o;
	scanf("%d %d %d",&o.day,&o.month,&o.year);
	scanf("%d %d %d",&e.day,&e.month,&e.year);
	if(e.year > o.year)
		{
			printf("0" );
			return 0 ;
		}
	if(e.year < o.year)
	{
		printf("10000");
		return 0;
		

	}
	
		if(e.month > o.month)
		{
			printf("0");
			return 0 ;
		}
	if(e.month < o.month)
	{
		printf("%d",(o.month-e.month)*500);
		return 0;
		
	}
	if(e.day < o.day)
	{
		printf("%d",(o.day-e.day)*15 );
		return 0;
	}
	printf("0");
	return 0 ;
	//printf("%d %d %d",o.day,o.month,o.year);
}