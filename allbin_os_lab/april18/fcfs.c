#include <stdio.h>
int main()
{
    int pid[15];
    int bt[15];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter process id of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&pid[i]);
    }
    printf("Enter burst time of all the processes: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    int i, wt[n];
    wt[0]=0;
    for(i=1; i<n; i++)
    {
        wt[i]= bt[i-1]+ wt[i-1];
    }
    printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
    float twt=0.0;
    float tat= 0.0;
    for(i=0; i<n; i++)
    {
        printf("%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\t\t", bt[i]+wt[i]);
        printf("\n");
        twt += wt[i];
        tat += (wt[i]+bt[i]);
    }
    printf("Gantt Chart:\n");
    int last = bt[n-1] + (n == 1 ? 0: wt[n-1]); 
    
    printf(" ");
    for(int i=0; i<n; i++) {
        for(int j=0; j<bt[i]; j++) 
        	printf("--");
        printf(" ");
    }
    printf("\n|");
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<bt[i-1]; j++) printf(" ");
        printf("%d", pid[i]);
        for(int j=0; j<bt[i-1]; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    
     for(int i=0; i<n; i++) {
        for(int j=0; j<bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    
    int minus = 0;
    for(int i=0; i<n; i++) {
        if(wt[i]>9) printf(" ");
        printf("%d", wt[i]);
        if(wt[i+1]>9){
          minus = 1;
        }
        if(i+1 == n )  if (last>9) minus = 1;
        for(int j=0; j<bt[i]-minus; j++) printf("  ");

    }
    if(last>9) printf(" ");
    	printf("%d\n", last);
        

    
    
    float att,awt;
    awt = twt/n;
    att = tat/n;
    printf("Avg. waiting time= %f\n",awt);
    printf("Avg. turnaround time= %f",att);
}
