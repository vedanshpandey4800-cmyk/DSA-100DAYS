#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    int speed;
} Car;

int compare(const void* a, const void* b) {
    return ((Car*)b)->pos - ((Car*)a)->pos; // descending
}

int carFleet(int target, int* position, int* speed, int n) {
    Car cars[n];

    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(Car), compare);

    int fleets = 0;
    double prevTime = 0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > prevTime) {
            fleets++;
            prevTime = time;
        }
    }

    return fleets;
}
