#include <stdio.h>

int main() {
    int n, i, j, temp;
    int wt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], wait[n], pid[n];

    printf("Enter CPU burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
        pid[i] = i + 1;
    }

    /* Sorting by burst time (SJF) */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (burst[i] > burst[j]) {
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    /* Waiting time calculation + output logic */
    wait[0] = 0;
    printf("Process %d WT = %d\n", pid[0], wait[0]);

    for (i = 1; i < n; i++) {
        wait[i] = wait[i - 1] + burst[i - 1];
        printf("Process %d WT = %d\n", pid[i], wait[i]);
        wt += wait[i];
    }

    printf("Average Waiting Time: %.2f\n", (float)wt / n);

    return 0;
}
