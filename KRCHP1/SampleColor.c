#include <stdio.h>

#define RED "\x1b[32m"
#define RESET "\x1b[0m"

int main()
{
	printf(RED"hello World"RESET);	
	
}
