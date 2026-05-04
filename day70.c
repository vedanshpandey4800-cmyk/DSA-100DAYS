#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int n = 5; // vertices
    int m = 8; // edges

    struct Edge edges[8] = {
        {0,1,-1}, {0,2,4}, {1,2,3}, {1,3,2},
        {1,4,2}, {3,2,5}, {3,1,1}, {4,3,-3}
    };

    int dist[n];

    // Step 1: initialize
    for(int i=0; i<n; i++)
        dist[i] = INT_MAX;

    dist[0] = 0; // source

    // Step 2: relax edges n-1 times
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: check negative cycle
    for(int j=0; j<m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Negative Weight Cycle Detected\n");
            return 0;
        }
    }

    // Print result
    printf("Vertex\tDistance from Source\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}
