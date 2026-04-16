#include <stdio.h>

#define N 5

#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];

void test(int i) {
    if (state[i] == HUNGRY &&
        state[(i+4)%N] != EATING &&
        state[(i+1)%N] != EATING) {

        state[i] = EATING;
        printf("Philosopher %d is Eating\n", i+1);
    }
}

void take_fork(int i) {
    state[i] = HUNGRY;
    printf("Philosopher %d is Hungry\n", i+1);

    test(i);

    if (state[i] != EATING)
        printf("Philosopher %d is Waiting\n", i+1);
}

void put_fork(int i) {
    state[i] = THINKING;
    printf("Philosopher %d is Thinking\n", i+1);

    test((i+4)%N);
    test((i+1)%N);
}

int main() {
    int ch;

    while (1) {
        printf("\nDining Philosophers\n");
        printf("1-5: Philosopher wants to eat\n");
        printf("6: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch >= 1 && ch <= 5) {
            take_fork(ch - 1);
            put_fork(ch - 1);
        }
        else if (ch == 6) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
