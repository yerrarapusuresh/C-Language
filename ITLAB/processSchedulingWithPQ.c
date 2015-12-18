#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
typedef struct processDetails
{
    int PID;
    double PAT ;
    double PBT ;
}process;

typedef struct processQueue
{
    process p ;
    struct processQueue * next ;
}pq ;

void putinQueue(pq ** head ,process input);
void getInput(process * input, int i);
pq * getNewProcess(process  input );
void disply(pq * head);

int main()
{
    signal(SIGINT,SIG_IGN);
    process input ;
    int totalProcess,i = 1  ;
    pq * HeadProcess = NULL ;
    
    
    printf("How many process Would like to enter:  \n");
    scanf("%d",&totalProcess);
    
    if(totalProcess < 2)
    {
            printf("Number of process atleast two \n");
            return - 1 ;
    }

    while( i <= totalProcess)
    {
       printf("please enter Details for Process No. %d\n",i);
       getInput(&input,i);
       putinQueue(&HeadProcess,input);
       i++ ;
       printf("\n\n");
    }

    disply(HeadProcess);

    return 0 ;
}

pq * getNewProcess(process  input )
{
    pq *  newProcess = malloc(sizeof(pq));
    newProcess->p.PID = input.PID ;
    newProcess->p.PAT = input.PAT ;
    newProcess->p.PBT = input.PBT ;
    
    return newProcess ;
}

void putinQueue(pq ** head ,process input )
{
    pq * newProcess = getNewProcess(input);

    if(*head == NULL ||( *head)->p.PAT >= newProcess->p.PAT)
    {
        newProcess->next =( *head) ;
        *head = newProcess ;
    }

    else
    {
        pq * temp = *head ;
        while( temp->next != NULL && temp->next->p.PAT < newProcess->p.PAT)
        {
            temp = temp->next ;
        }

        newProcess->next = temp->next ;
        temp->next = newProcess ;
    }

}

void getInput(process * input, int i)
{
    input->PID = i ;
    printf("\nenter process Arrival Time ");
    scanf("%lf",&(input->PAT));
    printf("\nEnter process Burst Time ");
    scanf("%lf",&(input->PBT));
}

void disply( pq * head )
{
    pq  * temp = head ;

    while(temp != NULL)
    {
        printf("PID = %d  PAT = %f PBT = %f \n",temp->p.PID,temp->p.PAT,temp->p.PBT);
        temp = temp ->next ;
    }
}














