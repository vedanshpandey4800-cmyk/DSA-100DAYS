#include <stdio.h>
#define SIZE 10

int table[SIZE];

// initialize table
void init() {
    for(int i = 0; i < SIZE; i++)
        table[i] = -1;
}

// hash function
int hash(int key) {
    return key % SIZE;
}

// insert using quadratic probing
void insert(int key) {
    int h = hash(key);

    for(int i = 0; i < SIZE; i++) {
        int index = (h + i*i) % SIZE;

        if(table[index] == -1) {
            table[index] = key;
            return;
        }
    }

    printf("Table Full\n");
}

// search
void search(int key) {
    int h = hash(key);

    for(int i = 0; i < SIZE; i++) {
        int index = (h + i*i) % SIZE;

        if(table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if(table[index] == -1) {
            break;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    init();

    int q;
    scanf("%d", &q);

    while(q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if(op[0] == 'I') {
            insert(key);
        } else if(op[0] == 'S') {
            search(key);
        }
    }

    return 0;
}
