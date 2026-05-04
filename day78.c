#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int n, m;

// Find minimum key vertex not yet included
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 1; v <= n; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

int primMST() {
    int key[MAX];     // minimum weight
    int mstSet[MAX];  // included in MST

    // Initialize
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[1] = 0; // start from node 1

    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize graph
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = 0;

    // Input edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int result = primMST();
    printf("%d\n", result);

    return 0;
}
