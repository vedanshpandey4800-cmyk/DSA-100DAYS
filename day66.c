#include <stdbool.h>

bool dfs(int node, int** graph, int* graphSize, int* state) {
    if (state[node] == 1) return true;   // cycle
    if (state[node] == 2) return false;  // already safe

    state[node] = 1; // visiting

    for (int i = 0; i < graphSize[node]; i++) {
        int next = graph[node][i];
        if (dfs(next, graph, graphSize, state)) {
            return true;
        }
    }

    state[node] = 2; // done
    return false;
}

bool hasCycle(int n, int** graph, int* graphSize) {
    int state[n];

    for (int i = 0; i < n; i++) state[i] = 0;

    for (int i = 0; i < n; i++) {
        if (dfs(i, graph, graphSize, state)) {
            return true;
        }
    }

    return false;
}
