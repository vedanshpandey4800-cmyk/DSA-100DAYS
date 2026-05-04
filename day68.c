#include <stdlib.h>

void topoSort(int n, int** graph, int* graphSize) {
    int* indegree = (int*)calloc(n, sizeof(int));

    // Calculate indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graphSize[i]; j++) {
            indegree[graph[i][j]]++;
        }
    }

    // Queue
    int* queue = (int*)malloc(n * sizeof(int));
    int front = 0, rear = 0;

    // Push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // Process
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < graphSize[node]; i++) {
            int next = graph[node][i];
            indegree[next]--;

            if (indegree[next] == 0) {
                queue[rear++] = next;
            }
        }
    }
}
