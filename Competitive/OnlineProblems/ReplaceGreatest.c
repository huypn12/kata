#include "stdafx.h"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *replaceElements(int *arr, int arrSize, int *returnSize)
{
    int resSize = arrSize * sizeof(int);
    int *res = (int *) malloc(resSize);
    if (res == NULL) {
        *returnSize = 0;
        return NULL;
    }
    memset(res, 0, resSize);

    int max = arr[arrSize - 1];
    res[arrSize - 1] = -1;
    for (int i = arrSize - 2; i >= 0; i--) {
        res[i] = max;
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    *returnSize = resSize;
    return res;
}

void test()
{
    int input[6] = {17, 18, 5, 4, 6, 1};
    int expected[6] = {18, 6, 6, 6, 1, -1};
    int returnSize = 0;
    int *output = replaceElements(input, 6, &returnSize);
    for (int i = 0; i < 6; i++) {
        printf("%d %d\n", i, output[i]);
        assert(output[i] == expected[i]);
    }
    if (returnSize > 0)
        free(output);
}

int main()
{
    test();

    return 0;
}