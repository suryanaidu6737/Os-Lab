#include<stdio.h>
int main()
{
        int n,i,j,temp,wt=0;
        printf("enter no:of processes:");
        scanf("%d",&n);
        int burst[n],pri[n],wait[n],pid[n];
        printf("enter burst times:\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&burst[i]);
        }
        printf("enter priorities :\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&pri[i]);
        }
        for(i=0;i<n;i++)
        {
           pid[i]=i+1;
        }
        for(i=0;i<n-1;i++)
        {
                for(j=i+1;j<n;j++)
                {
                    if(pri[j]<pri[i])
                    {
                        temp=pri[i];
                        pri[i]=pri[j];
                        pri[j]=temp;

                        temp=burst[i];
                        burst[i]=burst[j];
                        burst[j]=temp;

                        temp=pid[i];
                        pid[i]=pid[j];
                        pid[j]=temp;
                    }
                }
        }
        wait[0]=0;
        printf("process %d wt=%d priority=%d\n",pid[0],wait[0],pri[0]);
        for(i=1;i<n;i++)
        {
            wait[i]=burst[i-1]+wait[i-1];
            printf("process %d wt=%d priority=%d\n",pid[i],wait[i],pri[i]);
            wt+=wait[i];    
        }
        printf("average wt is:%f",(float)wt/n);
        return 0;
}
