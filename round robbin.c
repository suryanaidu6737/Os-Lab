#include<stdio.h>
void main()
{
	int n,i,j,tq,awt=0,atat=0;
	printf("enter no:of processes");
	scanf("%d",&n);
	int burst[n],rt[n],at[n],wt[10],tat[n];
	printf("enter burst times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&burst[i]);
		rt[i]=burst[i];
	}
	printf("enter arrival times:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("enter time quantum");
	scanf("%d",&tq);
	int completed=0,time=0;
	while(completed!=n)
	{
		int found=0;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && rt[i]>0)
			{
				found=1;
				if(rt[i]>tq)
				{
					rt[i]-=tq;
					time+=tq;
				}
				else
				{
					time+=rt[i];
					rt[i]=0;
					completed++;		
					tat[i]=time-at[i];
					wt[i]=tat[i]-burst[i];
				}
			}
		}
		if(!found)
			time++;
	}
	printf("process\t at\t bt\t wt\t tat\n");
	for(i=0;i<n;i++)
	{
		printf("p%d\t%d\t%d\t%d\t%d\n",i+1,at[i],burst[i],wt[i],tat[i]);
		awt+=wt[i];
		atat+=tat[i];
	}
	printf("awt=%.2f\tatat=%.2f",(float)awt/n,(float)atat/n);
}
			
				
					
			
				
		
	
	
