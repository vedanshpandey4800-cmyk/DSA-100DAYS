#include <stdio.h>
#include <stdlib.h>

// Define structure of doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n, i, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    // Create doubly linked list
    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory dynamically
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Traverse in forward direction
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}