#include "stdafx.h"


/*
 * Median-of-Median algorithm
 */

int __Split(int *A, int l, int r)
{
  return 0;
}


int MSelect(int *A, int l, int r, int k)
{
  if (l - r <= 10) {
  }

  return 0;
}

/*
 * Quickselect algorithm
 */
int __Partition() {}

int QSelect()
{
 
}


/*
 * Heap based algorithm
*/


/*
 * Floyd-Rivest algorithm
 */

/*
 * Generate test data
 */
int *GenerateTestData(int arrSize)
{
  int *test_data = (int *) malloc(sizeof(int) * arrSize);
  assert(test_data != NULL);
  for (int i = 0; i < arrSize; i++) {
    
  }
}


int findKthLargest(int* nums, int numsSize, int k)
{
#if defined(QSELECT)
    return QSelect(nums, 0, numsSize, k);
#elif defined(KSELECT)
    return KSelect(nums, 0, numsSize, k);
#elif defined(HSELECT)
#elif defined(FSELECT)
#endif
}

void Test()
{
#define QSELECT
#undef QSELECT
#define KSELECT
#undef KSELECT
}
