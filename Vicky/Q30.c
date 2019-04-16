/**Write a C program to solve the following problem:
Suppose that a disk drive has 5,000 cylinders, numbered 0 to 4999. The drive is currently serving a request at cylinder143, and the previous request was at cylinder 125. The queue of pending requests, in FIFO order,is:
86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130
Starting from the current head position, what is the total distance (in cylinders) that the disk arm moves to satisfy all the pending requests for each of the FCFS disk-scheduling algorithms?
*/

#include<stdio.h>
int main(){
    int n;
    int previous,cur;
    printf("Enter number of processes: \n");
    scanf("%d",&n);
    int queue[n];
    printf("Enter the Previous Requested position\n");
    scanf("%d",&previous);
    printf("Enter the current header position\n");
    scanf("%d",&cur);
    printf("Enter Processes in sequence: \n");
    for(int j = 0;j<n;j++){
        scanf("%d",&queue[j]);
    }
    int total =0 ;
    if (previous>cur){
        total = previous+cur;
        
    }
    else{
        total = cur-previous;
    }
   for (int i = 0;i<n;i++){
        if (queue[i]>cur){
            total += (queue[i]-cur);
            cur = queue[i];
            
        }
        else{
            total += (cur-queue[i]);
           cur = queue[i];
    }
        
    }
    printf("Total distance arm moves: %d\n", total);
}
