#include <stdio.h>

int main() {
    int frames, pages;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int ref[pages], frame[frames], time[frames];

    printf("Enter reference string:\n");
    for(int i = 0; i < pages; i++) {
        scanf("%d", &ref[i]);
    }

    // Initialize frames
    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    int pageFaults = 0, counter = 0;

    for(int i = 0; i < pages; i++) {
        int found = 0;

        // Check if page is present
        for(int j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                counter++;
                time[j] = counter;  // update recent use
                found = 1;
                break;
            }
        }

        // If not found → page fault
        if(!found) {
            int min = time[0], pos = 0;

            // Find least recently used page
            for(int j = 0; j < frames; j++) {
                if(frame[j] == -1) {
                    pos = j;
                    break;
                }
                if(time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            frame[pos] = ref[i];
            counter++;
            time[pos] = counter;
            pageFaults++;
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}
