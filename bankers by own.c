#include<stdio.h>
int main()
{
        int alloc[10][10],max[10][10],need[10][10];
        int n,m,i,j,avail[10],work[10],finish[10];
        printf("enter no:of processes:");
        scanf("%d",&n);
        printf("enter no:of resources:");
        scanf("%d",&m);
        printf("enter allocated resources\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&alloc[i][j]);
            }
        }
        printf("enter maximum resources\n");
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&max[i][j]);
                need[i][j]=max[i][j]-alloc[i][j];
            }
        }
        /*initialization*/
        printf("enter available resources:");
        for(i=0;i<m;i++)
        {
            scanf("%d",&avail[i]);
            work[i]=avail[i];
        }
        for(i=0;i<n;i++)
        {
            finish[i]=0;
        }
        for(i=0;i<n;i++)
        {   
            if(finish[i]==0)
            {
                for(j=0;j<m;j++)
                {
                    if(need[i][j]<=work[j])
                    {
                        work[j]+=alloc[i][j];
                        finish[i]=1;
                    }
                }
            }
        }
    }
        
