#include <stdio.h>
#define INF 9999
#define MAX 5

void dijkstra(int G[MAX][MAX], int start) {
    int dist[MAX], pred[MAX], visited[MAX];
    int i, j, count, nextNode, minDist;

    for(i = 0; i < MAX; i++) {
        dist[i] = (G[start][i] == 0 && i != start) ? INF : G[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    dist[start] = 0;
    count = 1;

    while(count < MAX) {
        minDist = INF;
        for(i = 0; i < MAX; i++)
            if(!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                nextNode = i;
            }

        visited[nextNode] = 1;

        for(i = 0; i < MAX; i++)
            if(!visited[i] && G[nextNode][i] != 0 &&
               minDist + G[nextNode][i] < dist[i]) {
                dist[i] = minDist + G[nextNode][i];
                pred[i] = nextNode;    // <-- FIXED LINE
            }

        count++;
    }

    printf("\nShortest paths from %c:\n", start + 'A');
    for(i = 0; i < MAX; i++) {
        if(i != start) {
            printf("To %c: Distance = %d | Path = %c", i+'A', dist[i], start+'A');
            int path[MAX],idx=0;
            j = i;
            while(j != start) {
                path[idx++]=j;
                j = pred[j];
            }
            for(int k=idx-1;k>=0;k--){
                printf(" -> %c", path[k]+'A');
            }
            
            printf("\n");
        }
    }
}

int main() {
    int G[MAX][MAX], i, j;

    printf("Enter adjacency matrix (0 means no link except diagonal):\n");
    for(i = 0; i < MAX; i++)
        for(j = 0; j < MAX; j++)
            scanf("%d", &G[i][j]);

    printf("\n--- Adjacency Matrix ---\n");
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++)
            printf("%4d", G[i][j]);
        printf("\n");
    }

    for(i = 0; i < MAX; i++)
        dijkstra(G, i);

    return 0;
}