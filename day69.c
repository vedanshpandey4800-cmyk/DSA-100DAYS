#include <stdio.h>
#include <limits.h>

#define V 100   // max nodes

// Find node with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

// Dijkstra function
void dijkstra(int graph[V][V], int n, int src) {
    int dist[V];
    int visited[V];

    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Loop for all nodes
    for (int count = 0; count < n - 1; count++) {

        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        // Update neighbors
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print result
    printf("Node \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

// Driver code
int main() {
    int n = 5;

    int graph[V][V] = {
        {0, 4, 1, 0, 0},
        {4, 0, 2, 1, 0},
        {1, 2, 0, 5, 0},
        {0, 1, 5, 0, 3},
        {0, 0, 0, 3, 0}
    };

    int src = 0;

    dijkstra(graph, n, src);

    return 0;
}
