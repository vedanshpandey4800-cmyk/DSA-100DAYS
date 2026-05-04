#include <stdio.h>

void dfs(int node, int n, int adj[n][n], int visited[]) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int adj[n][n];

    // input adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int start;
    scanf("%d", &start);

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(start, n, adj, visited);

    return 0;
}
