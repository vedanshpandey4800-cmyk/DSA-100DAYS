#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long inv = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += (mid - i + 1); // inversion count
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        inv += mergeSort(arr, temp, left, mid);
        inv += mergeSort(arr, temp, mid + 1, right);
        inv += merge(arr, temp, left, mid, right);
    }

    return inv;
}

long long countInversions(int arr[], int n) {
    int temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;

    printf("%lld", countInversions(arr, n)); // Output: 3
    return 0;
}
