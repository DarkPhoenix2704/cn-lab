#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i, x1 = 18;
    int numFrames;
    srand(x1++);

    numFrames = rand() % 200;
    numFrames = numFrames / 22000;

    printf("\nNumber of frames: %d\n", numFrames);

    for (i = 0; i < numFrames; i++) {
        printf("\nSending frame %d\n", i + 1);
        srand(x1++);

        if (x1 % 2 == 0) {
            printf("Waiting for 1 second\n");
            sleep(1);
            printf("Missing Acknowledgement 1\n");
            printf("Resending frame %d\n", i + 1);
        }

        printf("Acknowledgement received for frame %d\n", i + 1);
    }

    printf("\nEnd of Stop and Wait protocol\n");

    return 0;
}
