#include <stdio.h>
#include <stdlib.h>

void inputFrames(int frames[], int frameSize) {
    printf("\nInput\n");
    for (int i = 1; i <= frameSize; i++) {
        printf("Enter value for frame[%d]: ", i);
        scanf("%d", &frames[i]);
        printf("\n");
    }
}

void displayFrames(int frames[], int frameSize) {
    printf("\nDisplay\n");
    for (int i = 1; i <= frameSize; i++) {
        printf("Frame [%d]: %d\n", i, frames[i]);
    }
}

void selectiveRepeat(int frames[], int windowSize, int frameSize) {
    int totalTransmissions = 0;
    int k = 0;
    int left[10000] = {-1};
    int i;
    
    for (i = 1; i <= frameSize; i++) {
        int flag = rand() % 2;
        
        if (!flag) {
            printf("Frame[%d] with value %d acknowledged!\n", i, frames[i]);
            totalTransmissions++;
        } else {
            printf("Frame[%d] with value %d not acknowledged!\n", i, frames[i]);
            left[k++] = frames[i];
            totalTransmissions++;
        }
        
        if (i % windowSize == 0) {
            for (int x = 0; x < k; x++) {
                printf("Frame[%d] with value %d retransmitted\n", x, left[x]);
                totalTransmissions++;
                printf("Frame[%d] with value %d acknowledged on second attempt\n", x, left[x]);
            }
            k = 0;
        }
    }

    for (i = 0; i < k; i++) {
        printf("Frame[%d] with value %d retransmitted\n", i, left[i]);
        totalTransmissions++;
        printf("Frame[%d] with value %d acknowledged on second attempt\n", i, left[i]);
    }

    printf("Total transmissions: %d\n\n", totalTransmissions);
}

int main() {
    int frames[50];
    int windowSize;
    int frameSize;
    
    printf("\nSelective Repeat\n");
    
    printf("Enter window size: ");
    scanf("%d", &windowSize);
    
    printf("Enter number of frames to be transmitted: ");
    scanf("%d", &frameSize);
    
    inputFrames(frames, frameSize);
    displayFrames(frames, frameSize);
    selectiveRepeat(frames, windowSize, frameSize);
    
    return 0;
}
