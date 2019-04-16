/**Considering the arrival time and burst time requirement of the process the scheduler schedules the processes by interrupting the processor after every 6 units of time and does consider the completion of the process in this iteration. The scheduler than checks for the number of process waiting for the processor and allots the processor to the process but interrupting the processor every 10 unit of time and considers the completion of the processes in this iteration. The scheduler checks the number of processes waiting in the queue for the processor after the second iteration and gives the processor to the process which needs more time to complete than the other processes to go in the terminated state.
The inputs for the number of requirements, arrival time and burst time should be provided by the user.
Consider the following units for reference.
Process Arrival time Burst time
P1 0 20
P2 5 36
P3 13 19
P4 26 42
Develop a scheduler which submits the processes to the processor in the defined scenario, and compute the scheduler performance by providing the waiting time for process, turnaround time for process and average waiting time and turnaround time.
*/

#include<stdio.h>

void findavgTime(int n, int bt[],int curt,int wt[n],int tat[],int bsT[]);
void findWaitingTime(int n,int bt[], int wt[]);
void findTurnAroundTime(int n,int bt[], int wt[], int tat[]);
int main()
{
    int Proc_no,j,no,CurT,RemProc,indicator,time_quan,wait[10],tut[10],arT[10],bsT[10],remt[10],x=1;
    indicator = 0;
    printf("Enter number of processes ");
    scanf("%d",&no);
    RemProc = no;
    
    printf("\nEnter the arrival time and burst time of the processes\n");
    for(Proc_no = 0;Proc_no < no;Proc_no++)
    {
        printf("\nProcess P%d\n",Proc_no+1);
        printf("Arrival time = ");
        scanf("%d",&arT[Proc_no]);
        printf("Burst time = ");
        scanf("%d",&bsT[Proc_no]);
        remt[Proc_no]=bsT[Proc_no];
    }
    printf("The details of time quantum are as follows:\n");
    printf("The time quantum for first round is 6.\n");
    time_quan=6;
    CurT=0;
    for(Proc_no=0;RemProc!=0;)
    {
        if(remt[Proc_no]<=time_quan && remt[Proc_no]>0)
        {
            CurT+=remt[Proc_no];
            remt[Proc_no]=0;
            indicator=1;
        }
        else if(remt[Proc_no]>0)
        {
            remt[Proc_no]-=time_quan;
            CurT+=time_quan;
            wait[Proc_no]=CurT-arT[Proc_no]-bsT[Proc_no];
            tut[Proc_no]=CurT-arT[Proc_no];
        }
        if(remt[Proc_no]==0 && indicator==1)
        { 
            RemProc--;
            wait[Proc_no]=CurT-arT[Proc_no]-bsT[Proc_no];
            tut[Proc_no]=CurT-arT[Proc_no];
            indicator=0;
            
        }
        if(Proc_no==no-1){
            x++;
            if(x==2){
                Proc_no=0;
                time_quan=10;
                
                printf("The time quantum for second round is 10. \n");
            }
            else{
                break;
            }
        }
        else if(CurT >= arT[Proc_no+1]){
            
            Proc_no++;
        }
        else{
            Proc_no=0;
        }
    }
    findavgTime(no,remt,CurT,wait,tut,bsT);
    
    return 0;
}


void findWaitingTime(int n,int bt[], int wt[])
{
    
    // calculating waiting time
    for (int  i = 1; i < n ; i++ ){
        wt[i] =  bt[i] + wt[i] ;}
        //printf("\n%d\n",wt[i]);}
}

// Function to calculate turn around time
void findTurnAroundTime(int n,int bt[], int wt[], int tat[])
{
    // calculating turnaround time by adding
    // bt[i] + wt[i]
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

//Function to calculate average time
void findavgTime(int n, int bt[],int curt,int wt[n],int tat[],int bsT[])
{
    int total_wt = 0, total_tat = 0;
    
    //Function to find waiting time of all processes
    findWaitingTime(n, bt, wt);
    
    //Function to find turn around time for all processes
    findTurnAroundTime( n, bsT, wt, tat);
    
    //Display processes along with all details
    printf("Processes \t  Burst time  \t\t Waiting time  \t\t Turn around time\n");
    
    //Calculate total waiting time and total turn
    // around time
    for (int  i=0; i<n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("P %d ",(i+1));
        printf("\t\t\t%d ", bt[i] );
        printf("\t\t\t%d",wt[i] );
        printf("\t\t\t%d\n",tat[i] );
    }
    float s=(float)total_wt / (float)n;
    float t=(float)total_tat / (float)n;
    printf("Average waiting time = %f",s);
    printf("\n");
    printf("Average turn around time = %f ",t);
}
