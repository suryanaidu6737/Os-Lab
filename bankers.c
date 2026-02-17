#include<stdio.h>

int main()
{
    int alloc[10][10], max[10][10], need[10][10];
    int n, m, i, j;
    int avail[10], work[10], finish[10];
    int safeSeq[10];
    int count = 0, found, possible;

    printf("Enter no of processes: ");
    scanf("%d", &n);

    printf("Enter no of resources: ");
    scanf("%d", &m);

    printf("Enter allocation matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter maximum matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }

    printf("Enter available resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
        work[i] = avail[i];
    }

    for(i = 0; i < n; i++)
        finish[i] = 0;

    while(count < n)
    {
        found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible == 1)
                {
                    for(j = 0; j < m; j++)
                        work[j] += alloc[i][j];

                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == n)
    {
        printf("\nSystem is in SAFE state\nSafe sequence: ");
        for(i = 0; i < n; i++)
            printf("P%d ", safeSeq[i]);
    }
    else
    {
        printf("\nSystem is NOT in safe state\n");
    }

    return 0;
}
