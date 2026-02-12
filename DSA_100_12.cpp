#include <stdio.h>

int main() {
    int m, n;
    int matrix[100][100];
    int i, j;
    int symmetric = 1;

    // Input rows and columns
    scanf("%d %d", &m, &n);

    // Input matrix elements
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if square matrix
    if(m != n) {
        printf("Not a Symmetric Matrix");
        return 0;
    }

    // Check symmetry condition
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
        if(symmetric == 0)
            break;
    }

    // Output result
    if(symmetric)
        printf("Symmetric Matrix");
    else
        printf("Not a Symmetric Matrix");

    return 0;
}

