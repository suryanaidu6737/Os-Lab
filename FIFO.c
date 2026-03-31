#include <stdio.h>

int main() {
    int frames, pages;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[pages], frame[frames];

    printf("Enter reference string:\n");
    for(int i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }

    // Initialize frames as empty
    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    int pageFaults = 0;
    int index = 0;

    for(int i = 0; i < pages; i++) {
        int found = 0;

        // Check if page is already in frame
        for(int j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        // If not found → replace using FIFO
        if(!found) {
            frame[index] = ref[i];
            index = (index + 1) % frames;
            pageFaults++;
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}
