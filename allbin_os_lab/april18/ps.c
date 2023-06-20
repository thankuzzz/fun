#include<stdio.h>
 
int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           
    }
 
    
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;     
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
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
        printf("%d", p[i]);
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
 
    avg_tat=total/n;    
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
    return 0;
}
