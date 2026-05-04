#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages) return 0;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            students++;
            pagesSum = arr[i];

            if (students > m) return 0;
        }
    }
    return 1;
}

int allocatePages(int arr[], int n, int m) {
    if (m > n) return -1;

    int sum = 0, maxVal = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int low = maxVal, high = sum, result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = 4, m = 2;

    printf("%d\n", allocatePages(arr, n, m)); // Output: 113

    return 0;
}
