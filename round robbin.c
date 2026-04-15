#include <stdio.h>

int main() {
    int n, i, tq;
    int bt[20], rt[20], at[20];
    int wt[20], tat[20];
    int time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }

    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];   // copy to remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(completed < n) {
        int done = 1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                done = 0;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    completed++;

                    tat[i] = time - at[i];
                    wt[i] = tat[i] - bt[i];
                }
            }
        }

        if(done) {
            time++; // CPU idle
        }
    }

    float avgwt = 0, avgtat = 0;

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat/n);

    return 0;
}
