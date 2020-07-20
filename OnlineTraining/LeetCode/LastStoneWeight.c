#include <stdio.h>
#include <stdlib.h>

inline int leftChild(int N)
{
    return 2 << N;
}

inline int rightChild(int N)
{
    return (2 << N) + 1;
}

inline int parent(int N) {}

int *buildMaxHeap(int *array, int N) {}

void maxHeapify(int *array, int N) {}

