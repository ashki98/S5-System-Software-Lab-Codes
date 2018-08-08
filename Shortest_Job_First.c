#include <stdio.h>
struct node{
  int num,burst_time,turnaround,wait;
}process[10];
void bsortDesc(struct node process[], int s)
{
    int i, j;
    struct node temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (process[j].burst_time > process[j + 1].burst_time)
            {
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
}
void main () {
  int n,k;
  printf("Input the number of processes:" );
  scanf("%d",&n );
  for(k=0;k<n;k++){
    process[k].num=k;
    printf("Enter the burst time of process%d:",process[k].num);
    scanf("%d",&process[k].burst_time);
  }
  bsortDesc(process, n);
  process[0].wait=0;
  for(k=1;k<n;k++){
    process[k].wait=process[k-1].burst_time+process[k-1].wait;
  }
  for(k=0;k<n;k++){
    process[k].turnaround=process[k].burst_time+process[k].wait;
  }
  printf("Process\t\tBurst Time\t\tWaitding Time\t\tTurnaround Time\n");
  for(k=0;k<n;k++){
    printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\n",process[k].num,process[k].burst_time,process[k].wait,process[k].turnaround);
  }
}
