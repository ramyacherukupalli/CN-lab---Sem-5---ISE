#include <stdio.h>
#define INFINITY 9999
#define N 5  // Number of nodes (A–E)

// Function to print path in forward direction (A -> B -> C)
void printPath(int previous[], int source, int dest) {
    int path[N], count = 0;
    int current = dest;

    // Backtrack from destination to source
    while (current != source) {
        path[count++] = current;
        current = previous[current];
    }
    path[count++] = source;

    // Print in reverse order (source → dest)
    for (int i = count - 1; i >= 0; i--) {
        printf("%c", path[i] + 'A');
        if (i > 0) printf(" -> ");
    }
}

// Function to perform Dijkstra’s algorithm
void dijkstra(int graph[N][N], int source) {
    int distance[N], visited[N], previous[N];
    int i, j, count, mindistance, nextnode;

    // Initialization
    for (i = 0; i < N; i++) {
        distance[i] = graph[source][i];
        previous[i] = source;
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;
    count = 1;

    while (count < N - 1) {
        mindistance = INFINITY;

        // Find next node with minimum distance
        for (i = 0; i < N; i++)
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }

        visited[nextnode] = 1;

        // Update distances
        for (i = 0; i < N; i++)
            if (!visited[i] && (mindistance + graph[nextnode][i] < distance[i])) {
                distance[i] = mindistance + graph[nextnode][i];
                previous[i] = nextnode;
            }

        count++;
    }

    // Print results
    printf("\nShortest paths from node %c:\n", source + 'A');
    for (i = 0; i < N; i++) {
        if (i != source) {
            printf("To %c : Distance = %d | Path = ", i + 'A', distance[i]);
            printPath(previous, source, i);
            printf("\n");
        }
    }
}

int main() {
    int graph[N][N];
    int i, j, source;

    printf("Enter the cost adjacency matrix (use 9999 for no direct link):\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nNodes: A=0, B=1, C=2, D=3, E=4\n");
    printf("Enter source node number (0-4): ");
    scanf("%d", &source);

    dijkstra(graph, source);

    return 0;
}
