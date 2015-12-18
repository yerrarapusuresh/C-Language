#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct  record
{
	char name[30];
	char type[10];
	int lineDec ;
	int cur ;
	int linenum[100];
	struct  record * next ;
}Record;

void writef(FILE * ifp , FILE * ofp , Record ** head);
void checkForType(char buff[] ,char type[], int i, Record ** head);
void checkForQuotes(char buff[], char temp[]);
void filter(char buff[] , char tempbuff[] , char * character );
void search(FILE * ifp , Record * head);
Record * newRecord(char name[], char type[] , int linenum);
void insert(Record ** head , Record * newRecord);
void disply(Record * head);
void filterByChar(char buff[] , char * toremove);

int main(int argc , char * argv[])
{
	if(argc != 3)
	{
		printf("Usage : input.c output.c\n");
		return -1 ;
	}

	FILE * ifp = fopen(argv[1], "r");
	FILE * ofp = fopen(argv[2], "w");
	if(ifp == NULL || ofp == NULL)
	{
		if(ofp == NULL)
			printf("Unable to open %s\n",argv[2]);
		else
			printf("Unable to open %s\n",argv[1]);
		return -1 ;
	}
	Record * head = NULL ;
	writef(ifp, ofp, &head);
	
	fseek(ifp,0,SEEK_SET);
	search(ifp,head);
	disply(head);
	printf("\n");
	fclose(ifp);
	fclose(ofp);

}

void search(FILE * ifp , Record * head)
{
	char buff[MAX];
	char tempbuff[MAX];
	int i = 1 ;
	while(fgets(buff, MAX ,ifp) != NULL)
	{
		
		checkForQuotes(buff,tempbuff);
		filterByChar(buff,";");
		filterByChar(buff,",");
		filterByChar(buff,"(");
		filterByChar(buff,")");
		filterByChar(buff,"[");
		filterByChar(buff,"]");
		filterByChar(buff,"{");
		filterByChar(buff,"}");
		filterByChar(buff,"*");
		filterByChar(buff,"+");
		filterByChar(buff,"/");
		filterByChar(buff,"-");
		filterByChar(buff,">");
		filterByChar(buff,"<");
		filterByChar(buff,".");
		filterByChar(buff,"!");
		filterByChar(buff,"=");
		filterByChar(buff,"|");
		filterByChar(buff,"#");
		filterByChar(buff,"&");
		filterByChar(buff,"^");
		filterByChar(buff,"%");
		filterByChar(buff,"'");
		filterByChar(buff,"\n");

		char * temp ;
		Record * headtemp ;
		char string[100];

		for(temp = strtok(buff, " ") ; temp != NULL ; temp = strtok(NULL," "))
		{
			sscanf(temp, "%s", string);
			headtemp = head ;
			while(headtemp)
			{
				if(strcmp(headtemp->name , string) == 0)
				{
					headtemp->linenum[headtemp->cur++] = i ;
					break ;
				}
				headtemp = headtemp -> next ;
			}
			memset(string, '\0', 100);
		}

		i++;

	}
}
void filterByChar(char buff[] , char * toremove)
{
	char tempbuff[MAX];
	memset(tempbuff, '\0' ,MAX);
	char * temp ;
	for(temp = strtok(buff,toremove) ; temp != NULL ; temp = strtok(NULL,toremove))
	{
		strcat(tempbuff, temp);
		strcat(tempbuff," ");
	}
	memset(buff, '\0', MAX);
	strcpy(buff, tempbuff);
}

void writef(FILE * ifp , FILE * ofp , Record ** head)
{
	char buff[MAX];
	char tempBuff[MAX];
	int i = 1;
	

	while(fgets(buff, MAX, ifp) != NULL)
	{
		checkForQuotes(buff, tempBuff);

		if(strstr(buff,"int") != NULL)
		{
			memset(tempBuff,'\0',MAX);
			strcpy(tempBuff, buff);
			checkForType(tempBuff,"int", i , head);
			
		}
		if(strstr(buff, "char" )!= NULL)
		{
			strcpy(tempBuff, buff);
			checkForType(tempBuff, "char", i , head);	
			
		}
		if(strstr(buff, "float" )!= NULL)
		{
			strcpy(tempBuff, buff);
			checkForType(tempBuff, "float", i , head);	
		}

		if(strstr(buff, "double" )!= NULL)
		{
			strcpy(tempBuff, buff);
			checkForType(tempBuff,"double", i , head);	
		}
		i++;

	}

}
void checkForType(char buff[] , char type[], int linenum , Record ** head)
{
	char * loc = strstr(buff,type);
	if(isalnum(buff[loc - buff + strlen(type)]) )
		return ;
	if(loc - buff != 0)
	{
		if(buff[loc - buff - 1] == 9 || buff[loc - buff - 1] == ';'||buff[loc - buff - 1] == 11 ||buff[loc - buff - 1] == ' ' || buff[loc - buff - 1] == '(' || buff[loc - buff - 1] == '}')
		 ;	
		else 
			return ;

	}
	char tempbuff[1024];
	memset(tempbuff, '\0', 1024);
	filter(&buff[loc - buff], tempbuff , ",");

	char * token ;
	for(token = strtok(tempbuff+strlen(type)," "); token != NULL; token = strtok(NULL," "))
	{
		char temp[30];
		int i  ; 
		for(i = 0 ; isalnum(token[i]) || token[i] == '_' ; i++)
			temp[i] = token[i];
		temp[i] = '\0' ;
		if(token[i] == ';')
			break ;
		if(token[i] == '(')
			continue ;
		else
		{
			if(strlen(temp) > 0)
			//printf("|-%s-|\t",temp);
			insert(head, newRecord(temp , type,linenum ));
		}

	}
}

void checkForQuotes(char buff[], char temp[])
{
	memset(temp,'\0',MAX);

	if(strstr(buff,"\"") != NULL)
	{
		int i ;
		for( i = 0 ; buff[i] != '\"' ; i++ )
			temp[i] = buff[i] ;
		i++;
		//printf("check for quotes%d\n",buff[i]);
		for( ;buff[i] != '\"' && buff[i] != '\0' ; i++ )
			 ;


		if(buff[i] == '\0')
		{
			temp[i] = '\0';
			strcpy(buff, temp);
			return ;
		}
		i++;
		strcat(temp,&buff[i]);
		strcpy(buff,temp);

	}
}
void filter(char buff[] , char tempbuff[] , char * character )
{
	char * temp ;
	for(temp = strtok(buff,character) ; temp != NULL ; temp = strtok(NULL,character))
	{

		strcat(tempbuff, temp);
		strcat(tempbuff, " ");
	}

}

Record * newRecord(char name[], char type[] , int linenum)
{
	Record * nRecord = (Record *)malloc(sizeof(Record));
	strcpy(nRecord->name, name);
	strcpy(nRecord->type , type);
	nRecord->lineDec = linenum ;
	nRecord->cur  = 0 ;
	return nRecord ;
}
void insert(Record ** head , Record * newRecord)
{
	newRecord->next = * head ;
	*head = newRecord ;
	//printf("%s\n", newRecord->name);
}

void disply(Record * head)
{
	//printf("I am here \n");
	if(head == NULL)
		printf("something went wrong\n");
	while(head)
	{
		printf("Name : %s\n",head->name );
		printf("type : %s\n",head->type );
		printf("Line number its Declared : %d\n",head->lineDec );
		int i = 0 ;
		if(head->cur == 0)
			printf("variable never used \n");
		else
		{
			printf("variable used in line numbers : ");
			for( i = 1 ; i < head->cur ; i++)
				printf("%d\t",head->linenum[i]);
		}
		head = head->next ;
		printf("\n\n");

	}
}





