#include <stdio.h>

int main() {
    int n, m, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m], finish[n], safe[n];

    // Input Allocation Matrix
    printf("Enter Allocation matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input Maximum Matrix
    printf("Enter Maximum matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input Available Resources
    printf("Enter Available resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need Matrix
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Initialize Finish array
    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    // Safety Algorithm
    while(count < n) {
        int found = 0;   // Important fix

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int flag = 0;

                // Check Need <= Available
                for(j = 0; j < m; j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                // If process can be executed
                if(flag == 0) {
                    for(j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    safe[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process found → unsafe state
        if(found == 0) {
            printf("\nSystem is NOT in a safe state (Deadlock possible)\n");
            return 0;
        }
    }

    // If all processes finished → safe state
    printf("\nSystem is in SAFE state\n");
    printf("Safe sequence: ");
    for(i = 0; i < n; i++)
        printf("P%d ", safe[i]);

    return 0;
}
