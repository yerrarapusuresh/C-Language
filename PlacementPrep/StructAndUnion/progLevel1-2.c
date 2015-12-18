#include <stdio.h>

typedef struct student_s
{
	int sno ;
	char sname[20];
	char *cname ;
}student ;

int main()
{
	student s = {111,"xyz","stanford"}, *ps ;
	ps = &s ;
	printf("%s\n",(*ps).sname+1);
	ps->cname++ ;
	printf("%s",ps->cname+3);
	return 0 ;
}