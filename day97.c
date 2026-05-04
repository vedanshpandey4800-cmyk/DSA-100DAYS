#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Meeting;

int compare(const void* a, const void* b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

int minMeetingRooms(Meeting arr[], int n) {
    qsort(arr, n, sizeof(Meeting), compare);

    int* heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    // add first meeting end time
    heap[size++] = arr[0].end;

    for (int i = 1; i < n; i++) {
        // find smallest end time
        int minEnd = heap[0];

        if (arr[i].start >= minEnd) {
            // reuse room
            heap[0] = arr[i].end;
        } else {
            // need new room
            heap[size++] = arr[i].end;
        }

        // re-heapify (simple sort for clarity)
        for (int j = size - 1; j > 0 && heap[j] < heap[j - 1]; j--) {
            int temp = heap[j];
            heap[j] = heap[j - 1];
            heap[j - 1] = temp;
        }
    }

    int result = size;
    free(heap);
    return result;
}
