#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1024

typedef struct record 
{
	char find[100];
	char replace[100];
	struct record * next ;
} Record ;

Record * newRecord(char find[] , char replace[]);
void push(Record ** head , char find[] , char replace[]);
void disply(Record * head);
void writef(FILE * ifp , FILE * ofp,Record * head);
Record * search(Record *head , char * str);
void writeToFile(FILE * ifp , FILE *ofp , Record * head , char buff[]);

int main(int argc , char * argv[])
{
	if(argc != 3)
	{
		printf("Usage : program.c output.c\n");
		return -1 ;
	}
	char buff[MAX];
	FILE * ifp = fopen(argv[1],"r");
	if(ifp == NULL)
	{
		printf("Error : Unable to open %s file\n",argv[1] );
		return -1 ;
	}
	FILE * ofp = fopen(argv[2],"w");
	if(ofp == NULL)
	{
		printf("Error : Unable to open %s file\n",argv[1] );
		return -1 ;	
	}
	char * pointer = NULL ;
	Record * head = NULL ;
	while(fgets(buff,MAX,ifp) != NULL)
	{
		pointer = strstr(buff,"#define");
		if(pointer != NULL)
		{
			char find[100];
			char replace[100];
			sscanf(buff+strlen("#define"),"%s %s", find, replace);
			push(&head, find, replace);
		}
	}
	ifp = fopen(argv[1],"r");
	writef(ifp,ofp,head);
	

}

Record * newRecord(char find[] , char replace[])
{
	Record * newRecord = (Record *)malloc(sizeof(Record));
	strcpy(newRecord->find,find);
	strcpy(newRecord->replace, replace);
	return newRecord ;
}

void push(Record ** head , char find[] , char replace[])
{
	Record * newrecord = newRecord(find, replace);
	newrecord->next = *head ;
	*head = newrecord ;
}
void disply(Record * head)
{
	while(head)
	{
		printf("%s\t%s\n",head->find,head->replace);
		head = head->next ;
	}
}
Record * search(Record *head , char * str)
{
	while(head)
	{
		if(strstr(str, head->find) != NULL)
			return head ;
		head = head->next ;
	}
	return NULL ;
}

void writef(FILE * ifp , FILE * ofp , Record * head )
{
	char buff[MAX] ;
	int  i ;
	while(fgets(buff, MAX, ifp) != NULL)
	{
		if(strstr(buff, "#define") == NULL)
		{
			char * checkForQuote = strstr(buff,"\"");
			if(checkForQuote != NULL)
			{
				char tempbuff[MAX] ;
				int len = checkForQuote - buff ;
				strncpy(tempbuff, buff , len);
				if(len > 0)
					writeToFile(ifp, ofp , head , tempbuff);
				char * lastQuote = strrchr(buff, '\"');
				fprintf(ofp, "\"");
				for(i = ++len ; buff[i] != '\"' ; i++)
					fprintf(ofp,"%c",buff[i]);
				fprintf(ofp,"\"");
				writeToFile(ifp , ofp , head , &buff[++i]);
			}
			else
				writeToFile(ifp, ofp, head, buff);

		}
		
	}
}

void writeToFile(FILE * ifp , FILE *ofp , Record * head , char buff[])
{

		char * token ; 
		int i ;
		for(token = strtok(buff," ") ; token != NULL ; token = strtok(NULL, " "))
		{
			Record * temp = search(head, token);
			if(temp != NULL)
			{
				char * loc = strstr(token, temp->find);
				char c = token[loc - token + strlen(temp->find)] ;

				if(isalnum(c) || c == '_')
						fprintf(ofp, "%s ",token); 
				else
				{
					for(i = 0 ; i < loc - token ; i++)
						fprintf(ofp, "%c",token[i]);
					fprintf(ofp, "%s", temp->replace);
					fprintf(ofp, "%s ", &token[i + strlen(temp->find)]);
				}
			}
			else
				fprintf(ofp, "%s ", token );
		}
}