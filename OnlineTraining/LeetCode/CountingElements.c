#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 1001

int countElements(int *arr, int arrSize)
{
    int map[LIMIT];
    memset(map, 0xc0, sizeof(int) * LIMIT);

    // first loop to mark appearance
    for (int i = 0; i < arrSize; i++) {
        map[arr[i]] = 0;
    }

    // second loop to check expected number
    for (int i = 0; i < arrSize; i++) {
        if (map[arr[i] + 1] >= 0) {
            map[arr[i]] += 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < LIMIT; i++) {
        if (map[i] > 0) {
            sum += map[i];
        }
    }
    return sum;
}

int main()
{
    int arr[] = {1, 1, 2, 2};
    printf("\n %d", countElements(arr, sizeof(arr) / sizeof(int)));
    return 0;
}