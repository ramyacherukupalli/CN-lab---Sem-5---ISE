/*10. Packets from different flows arrive at a switch or router for processing.
A good scheduling technique treats the different flows in a fair and appropriate manner.
Implement priority queuing as a technique to improve Quality of Service.*/

#include <stdio.h>

#define MAX 100

struct Packet {
    int id;
    int priority;
    int arrivalOrder; // FIFO within same priority
};

int main() {
    struct Packet packets[MAX], temp;
    int n, i, j, choice;

    printf("----- Priority Queuing Simulation for QoS -----\n");
    printf("Enter the number of packets: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        packets[i].arrivalOrder = i;

        printf("\nEnter details for Packet %d:\n", i + 1);
        printf("Packet ID: ");
        scanf("%d", &packets[i].id);
        printf("Priority (0 = highest): ");
        scanf("%d", &packets[i].priority);
    }

    printf("\nChoose Scheduling Order:\n");
    printf("1. High to Low Priority (0 first)\n");
    printf("2. Low to High Priority\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    /* Sorting */
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {

            /* High → Low Priority */
            if (choice == 1) {
                if (packets[i].priority > packets[j].priority ||
                   (packets[i].priority == packets[j].priority &&
                    packets[i].arrivalOrder > packets[j].arrivalOrder)) {
                    temp = packets[i];
                    packets[i] = packets[j];
                    packets[j] = temp;
                }
            }

            /* Low → High Priority */
            else if (choice == 2) {
                if (packets[i].priority < packets[j].priority ||
                   (packets[i].priority == packets[j].priority &&
                    packets[i].arrivalOrder > packets[j].arrivalOrder)) {
                    temp = packets[i];
                    packets[i] = packets[j];
                    packets[j] = temp;
                }
            }
        }
    }

    printf("\n-------------------------------------------------\n");
    printf("| Packet ID | Priority | Processing Order       |\n");
    printf("-------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("| %9d | %8d | %-22d |\n",
               packets[i].id, packets[i].priority, i + 1);
    }

    printf("-------------------------------------------------\n");

    if (choice == 1)
        printf("\nScheduling: High to Low Priority (FIFO within same priority)\n");
    else
        printf("\nScheduling: Low to High Priority (FIFO within same priority)\n");

    printf("Simulation completed.\n");

    return 0;
}
