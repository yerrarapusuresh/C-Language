#include <stdio.h>

struct book_s
{
	int bno ;
	char bname[20] ;

};

typedef struct book_s book ;

main()
{
	book b1 = {100, "java"}, *pb1 ;
	pb1 = &b1 ;
	printf("%c ,%s",pb1->bname[1],pb1->bname+2);

}