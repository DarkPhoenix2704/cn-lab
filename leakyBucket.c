#include<stdio.h>

void main() {
    int in, out, bsize, n, bucket = 0;
    // in: incoming packet size
    // out: outgoing packet size
    // bsize: bucket size
    // n: number of inputs
    // bucket: bucket status


    printf("Enter the Bucket size:");
    // Read the bucket size
    scanf("%d", &bsize);
    printf("Enter the number of inputs:");
    // Read the number of inputs
    scanf("%d", &n);
    printf("Enter the packet outgoing rate:");
    // Read the packet outgoing rate
    scanf("%d", &out);
    while (n != 0) {
        printf("\nEnter the incoming packet size:");
        // Read the incoming packet size
        scanf("%d", &in);
        printf("Incoming packet size: %d\n", in);

        // If the incoming packet size (in) is less than or equal to the available space
        // in the bucket (bsize - bucket), the packet can be accommodated in the bucket without overflowing.
        // In this case, the code adds the incoming packet size to the bucket (bucket += in), and the bucket status
        // is printed, showing the updated number of packets in the bucket.
        if (in <= (bsize - bucket)) {
            bucket += in;
            printf("Bucket status: %d out of %d\n", bucket, bsize);
        } else {
            // If the incoming packet size is greater than the available space in the bucket,
            // it means that the bucket will overflow if the packet is added. In this scenario,
            // the code calculates the number of dropped packets by subtracting the available space
            // in the bucket from the incoming packet size (in - (bsize - bucket)). It then prints
            // the number of dropped packets and the bucket status (with the bucket being full).
            printf("Dropped packets: %d\n", in - (bsize - bucket));
            printf("Bucket status: %d out of %d\n", bucket, bsize);
            bucket = bsize;
        }
        bucket = bucket - out;
        printf("After outgoing, bucket status: %d packets out of %d\n", bucket, bsize);
        n--;
    }
}