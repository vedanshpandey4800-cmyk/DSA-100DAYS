#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// Helper function
struct Node* build(int* inorder, int inStart, int inEnd,
                   int* postorder, int postStart, int postEnd) {

    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = postorder[postEnd];  // root = last element
    root->left = root->right = NULL;

    // root ka index inorder me find karo
    int index;
    for (index = inStart; index <= inEnd; index++) {
        if (inorder[index] == root->val)
            break;
    }

    int leftSize = index - inStart;

    root->left = build(inorder, inStart, index - 1,
                       postorder, postStart, postStart + leftSize - 1);

    root->right = build(inorder, index + 1, inEnd,
                        postorder, postStart + leftSize, postEnd - 1);

    return root;
}

// preorder print
void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    struct Node* root = build(inorder, 0, n - 1,
                             postorder, 0, n - 1);

    preorder(root);

    return 0;
}
