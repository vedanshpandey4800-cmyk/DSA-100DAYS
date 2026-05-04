#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1, currSum = 0;

    for (int i = 0; i < n; i++) {
        if (currSum + arr[i] <= maxTime) {
            currSum += arr[i];
        } else {
            painters++;
            currSum = arr[i];

            if (painters > k) return 0;
        }
    }
    return 1;
}

int painterPartition(int arr[], int n, int k) {
    int low = arr[0], high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low) low = arr[i];
        high += arr[i];
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = 4, k = 2;

    printf("%d", painterPartition(arr, n, k)); // Output: 60
    return 0;
}
