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

    // Initialize frames
    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    int pageFaults = 0;

    for(int i = 0; i < pages; i++) {
        int found = 0;

        // Check if page already exists
        for(int j = 0; j < frames; j++) {
            if(frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        // If not found → page fault
        if(!found) {
            int pos = -1, farthest = i + 1;

            // Find page to replace
            for(int j = 0; j < frames; j++) {
                int k;

                // Look ahead in reference string
                for(k = i + 1; k < pages; k++) {
                    if(frame[j] == ref[k]) {
                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }
                        break;
                    }
                }

                // If page not found in future
                if(k == pages) {
                    pos = j;
                    break;
                }
            }

            // If all pages will be used again
            if(pos == -1) {
                pos = 0;
            }

            frame[pos] = ref[i];
            pageFaults++;
        }
    }

    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}
