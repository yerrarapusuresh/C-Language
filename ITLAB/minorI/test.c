#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  // int day, year;
  // char weekday[20], month[20], dtm[100];
	char final[100];
	int x,y,z ;
  // strcpy( dtm, "Saturday March 25 1989" );
   sprintf(final,"%d %d %d",23,24,25);
   sscanf(final,"%d %d %d",&x,&y,&z);
printf("this is working%d %d %d",x,y,z);
//   printf("%s %d, %d = %s\n", month, day, year, weekday );
    
   return(0);
}
