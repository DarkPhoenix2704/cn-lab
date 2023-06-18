#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numFrames, windowSize;
    int totalTransmissions = 0;
    srand(time(NULL));
    
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);
    
    printf("Enter the window size: ");
    scanf("%d", &windowSize);
    
    int currentFrame = 1;
    
    while (currentFrame <= numFrames) {
        int successfulTransmissions = 0;
        
        for (int frame = currentFrame; frame <= currentFrame + windowSize - 1 && frame <= numFrames; frame++) {
            printf("Sending frame %d\n", frame);
            totalTransmissions++;
        }
        
        for (int frame = currentFrame; frame < currentFrame + windowSize && frame <= numFrames; frame++) {
            int isAcknowledged = rand() % 2;
            
            if (isAcknowledged == 0) {
                printf("%d: Acknowledged!\n", frame);
                successfulTransmissions++;
            } else {
                printf("Frame %d not received\n", frame);
                printf("Retransmitting window\n");
                break;
            }
        }
        
        printf("\n");
        currentFrame += successfulTransmissions;
    }
    
    printf("Total number of transmissions: %d\n", totalTransmissions);
    
    return 0;
}