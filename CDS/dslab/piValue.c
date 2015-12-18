#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int findTerm(int term);

int main()
{
	
	findTerm(5);
}

int findTerm(int term )
{
	double Pi = 4 ;
	double step = 3.0 ;
	int i = 0 ;
	double add = 0 ;
	char input[100];
	char output[100];
	double val = 3.14159265359;
	snprintf(output,sizeof(output),"%f",val);
    output[term+2] = '\0';
	while(true )
		{
			if(i %2 == 0){
				add = -(4.0/step);
			}
			else{
				add = (4/step) ;
			}
			
			Pi = Pi + add ;
			snprintf(input,sizeof(input),"%f",Pi);
			if(strstr(input,output))
			{   printf("\n\n \t\t %f == %s == %s\n",Pi , input,output);
			    return 0;
			 }
			printf("\t%s   %s\n",input,output);

			++i ;
			step = step + 2 ;
			printf("%f\n",Pi);
	}

	
}
	
	





