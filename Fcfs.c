#include <stdio.h>
void main() {
    int n, i, wt = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int process[n], wait[n];
    printf("Enter process CPU burst times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &process[i]);
    wait[0] = 0;
    printf("Process %d WT = %d\n", 1, wait[0]);
    for (i = 1; i < n; i++) {
        wait[i] = wait[i-1] + process[i-1];
        printf("Process %d WT = %d\n", i+1, wait[i]);
        wt += wait[i];
    }
    printf("Average Waiting Time: %f\n", (float)wt/n);
}
