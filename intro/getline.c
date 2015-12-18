#include <stdio.h>

void get_line(char str[], int i ) ;

int main()
{	
	int MAXLINE = 100 ;
	char line[MAXLINE] ;
	get_line(line,MAXLINE);
	printf("%s",line);
	
}

void get_line(char str[], int i )
{
	int c  ;
	int j = 0 ;
	
	while(--i > 0 && (c = getchar()) != EOF && c != '\n')
		str[j++] = c ;
	if( c == '\n')
		str[j++] = c ;
	str[i] = '\0' ;
	
	
}
