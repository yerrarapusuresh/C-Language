#include <stdio.h>
#include <string.h>
void writeIt(char buffer[]);

FILE *temp ;

int main(int argc, char *argv[])
{       


	FILE *input ;
        int c ,i = 0 ,status ;
        char buffer[1000];
	
	
      	if(argc != 2)
        {
                printf("please enter input file .  \n");
                return -1 ;
        }

	char * input_file  = argv[1];
	
	if((temp = fopen("S_U_R_E_S_H.txt","a")) == NULL)
	{
		printf("Temp file could not opend !\n");
		return -1 ;
	}

        if((input = fopen(input_file,"r")) == NULL)
        {
                printf("input file does  not existed !\n");
                return -1 ;
        }

       while((c = fgetc(input)) != EOF)
        {
                if(c != '\n')
                {
                        buffer[i++] = c ;
                }
                else
                {
                        buffer[i] = '\n';
			buffer[++i] = '\0';
                        writeIt(buffer);
                        i = 0 ;
                }

        }
	status = remove(input_file);
	if(status != 0)
		printf("error\n");
	

	rename("S_U_R_E_S_H.txt",input_file);
       	fclose(input);
	fclose(temp);
}


void writeIt(char buffer[])
{
	char * loc = strstr(buffer,"student");
	long int place =(long) loc -(long)&(buffer[0]);
	int i ;
                if( loc != NULL)
                {
       			for( i = 0 ; i < place ; i++)
				fprintf(temp,"%c",buffer[i]);
                	fprintf(temp,"graduate");
			i += strlen("student")  ;
			writeIt(&buffer[i]);		
		}
	
	else 
		fprintf(temp,"%s",buffer);
}

