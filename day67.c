#include <stdio.h>
#include <stdlib.h>

void dfs(int node, int** graph, int* graphSize, int* visited, int* stack, int* top) {
    visited[node] = 1;

    for (int i = 0; i < graphSize[node]; i++) {
        int next = graph[node][i];
        if (!visited[next]) {
            dfs(next, graph, graphSize, visited, stack, top);
        }
    }

    stack[(*top)++] = node; // push after DFS
}

void topoSort(int n, int** graph, int* graphSize) {
    int visited[n];
    int stack[n];
    int top = 0;

    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, graphSize, visited, stack, &top);
        }
    }

    // Print reverse order
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}
