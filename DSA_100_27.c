#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create linked list
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

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
    return head;
}

// Function to get length of list
int getLength(struct Node* head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

int main() {
    int n, m;
    struct Node *head1, *head2;
    struct Node *temp1, *temp2;

    // Input first list
    scanf("%d", &n);
    head1 = createList(n);

    // Input second list
    scanf("%d", &m);
    head2 = createList(m);

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    temp1 = head1;
    temp2 = head2;

    // Move pointer of longer list ahead
    if(len1 > len2) {
        for(int i = 0; i < len1 - len2; i++)
            temp1 = temp1->next;
    } else {
        for(int i = 0; i < len2 - len1; i++)
            temp2 = temp2->next;
    }

    // Traverse together
    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->data == temp2->data) {
            printf("%d", temp1->data);
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    printf("No Intersection");
    return 0;
}