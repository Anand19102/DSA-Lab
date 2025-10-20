
#include <stdio.h>
#define INF 9999
#define MAX 10

int main() {
    int n, i, j, start;
    int cost[MAX][MAX], dist[MAX], visited[MAX], count, minDist, nextNode;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 9999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Step 1: Initialize distances and visited array
    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    // Step 2: Repeat until all vertices are visited
    while (count < n - 1) {
        minDist = INF;

        // Step 3: Find the unvisited vertex with the smallest distance
        for (i = 0; i < n; i++) {
            if (dist[i] < minDist && !visited[i]) {
                minDist = dist[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;

        // Step 4: Update distances of neighbors of nextNode
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (minDist + cost[nextNode][i] < dist[i]) {
                    dist[i] = minDist + cost[nextNode][i];
                }
            }
        }

        count++;
    }

    // Step 5: Print the shortest distances
    printf("\nShortest distances from vertex %d:\n", start);
    for (i = 0; i < n; i++) {
        if (i != start)
            printf("To vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}