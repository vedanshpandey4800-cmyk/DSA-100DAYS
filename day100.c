#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val, idx;
} Pair;

void merge(Pair arr[], int left, int mid, int right, int count[]) {
    int i = left, j = mid + 1, k = 0;
    Pair temp[right - left + 1];

    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].val <= arr[j].val) {
            count[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        count[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = 0; i < k; i++)
        arr[left + i] = temp[i];
}

void mergeSort(Pair arr[], int left, int right, int count[]) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(arr, left, mid, count);
    mergeSort(arr, mid + 1, right, count);
    merge(arr, left, mid, right, count);
}

int* countSmaller(int* nums, int n, int* returnSize) {
    Pair arr[n];
    int* count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1, count);

    *returnSize = n;
    return count;
}
