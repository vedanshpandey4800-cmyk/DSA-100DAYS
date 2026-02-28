#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value, key, count = 0;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Input key to count
    scanf("%d", &key);

    // Traverse and count occurrences
    temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            count++;
        }
        temp = temp->next;
    }

    // Print result
    printf("%d", count);

    return 0;
}