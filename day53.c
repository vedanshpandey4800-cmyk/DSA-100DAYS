#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree (level order)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

// Pair (node + hd)
struct Pair {
    struct Node* node;
    int hd;
};

// Vertical Order
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct Pair queue[1000];
    int front = 0, rear = 0;

    // map using arrays
    int minHD = 0, maxHD = 0;

    int result[2000][100]; // store values
    int size[2000] = {0}; // count per column

    queue[rear++] = (struct Pair){root, 0};

    while (front < rear) {
        struct Pair curr = queue[front++];

        int hd = curr.hd + 1000; // shift index

        result[hd][size[hd]++] = curr.node->data;

        if (curr.node->left)
            queue[rear++] = (struct Pair){curr.node->left, curr.hd - 1};

        if (curr.node->right)
            queue[rear++] = (struct Pair){curr.node->right, curr.hd + 1};

        if (curr.hd < minHD) minHD = curr.hd;
        if (curr.hd > maxHD) maxHD = curr.hd;
    }

    // print from leftmost to rightmost
    for (int i = minHD; i <= maxHD; i++) {
        int idx = i + 1000;
        for (int j = 0; j < size[idx]; j++) {
            printf("%d ", result[idx][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}
