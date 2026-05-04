#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int main()
{
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    int top = -1;

    // Push queue elements into stack
    for(int i = 0; i < n; i++)
    {
        stack[++top] = queue[i];
    }

    // Pop from stack back to queue
    for(int i = 0; i < n; i++)
    {
        queue[i] = stack[top--];
    }

    // Print reversed queue
    for(int i = 0; i < n; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}