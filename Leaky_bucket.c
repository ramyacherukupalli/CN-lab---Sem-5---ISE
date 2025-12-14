/*11.Write a program to achieve Traffic management at Flow level by implementing Leaky Bucket
Algorithm.*/

//CODE:
#include <stdio.h>

int main() {
    int bucketSize, outRate, n, i;

    printf("Enter the bucket size (in packets): ");
    scanf("%d", &bucketSize);

    printf("Enter the output rate (packets per tick): ");
    scanf("%d", &outRate);

    printf("Enter the number of input clock ticks: ");
    scanf("%d", &n);

    int pktIn[n];
    printf("Enter the number of packets coming at each tick:\n");
    for (i = 0; i < n; i++) {
        printf("Tick %d: ", i + 1);
        scanf("%d", &pktIn[i]);
    }

    int bucketContent = 0;

    printf("\n------------------------------------------------------------\n");
    printf("ClockTick | PktIn | PktOut | PktInBucket | PktDrop\n");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        int incoming = pktIn[i];
        int dropped = 0;

        // Step 1: Incoming packets enter the bucket
        if (bucketContent + incoming <= bucketSize) {
            bucketContent += incoming;
        } else {
            dropped = (bucketContent + incoming) - bucketSize;
            bucketContent = bucketSize; // bucket full
        }

        // Step 2: Leak (send out) packets at outRate
        int pktOut;
        if (bucketContent >= outRate) {
            pktOut = outRate;
            bucketContent -= outRate;
        } else {
            pktOut = bucketContent;
            bucketContent = 0;
        }

        printf("%9d | %5d | %6d | %12d | %7d\n",
               i + 1, incoming, pktOut, bucketContent, dropped);
    }

    printf("------------------------------------------------------------\n");
    return 0;
}
