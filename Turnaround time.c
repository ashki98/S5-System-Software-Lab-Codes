#include "stdio.h"

void main(){
  int process[10],n,burst_time[10],turnaround[10],i,wait[10];
  printf("Input the number of processes:");
  scanf("%d",&n);
  printf("Enter the burst time of each process\n");
  for(i=0;i<n;i++){
    process[i]=i;
    printf("Enter the burst time for process %d:",process[i]);
    scanf("%d",&burst_time[i] );
  }
  wait[0]=0;
  for(i=1;i<n;i++){
    wait[i]=burst_time[i-1]+wait[i-1];
  }
  for(i=0;i<n;i++){
    turnaround[i]=burst_time[i]+wait[i];
  }
  printf("Process\t\tBurst Time\t\tWaitding Time\t\tTurnaround Time\n");
  for(i=0;i<n;i++){
    printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",process[i],burst_time[i],wait[i],turnaround[i]);
  }
}
