#include "stdafx.h"

/*
    Optimal algorithm, kinda hard to implement
*/

int KSplit(int *A, int l, int r)
{

}

int KSelect(int *A, int l, int r, int k)
{
    if (l - r <= 10) {
        
    }

}

/*
 * Quickselect algorithm, easier to implement
*/
int QSelect()


/*
 * Heap based algorithm
*/

int findKthLargest(int* nums, int numsSize, int k)
{
#ifdef QSELECT
    return QSelect(nums, 0, numsSize, k);
#else
    return KSelect(nums, 0, numsSize, k);
#endif
}

void 
