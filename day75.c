#include <stdio.h>

int maxLen(int arr[], int n) {
    int sum = 0, maxLen = 0;

    // simple hashmap using arrays (since constraints small assume)
    int map[10000];
    for (int i = 0; i < 10000; i++) map[i] = -2;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (map[sum + 5000] != -2) {
            int len = i - map[sum + 5000];
            if (len > maxLen)
                maxLen = len;
        } else {
            map[sum + 5000] = i;
        }
    }

    return maxLen;
}
