#include "stdafx.h"
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static inline unsigned int __Abs(int x) { return (x < 0 ? x * -1 : x); }

int *findDuplicates(int *nums, int numsSize, int *returnSize) {
  int *res = (int *)malloc(sizeof(int) * (numsSize / 2 + 1));
  assert(res != NULL);
  memset(res, 0x0, (numsSize / 2 + 1) * sizeof(int));
  int res_top = 0;
  for (int i = 0; i < numsSize; i++) {
    if (nums[__Abs(nums[i]) - 1] > 0) {
      nums[__Abs(nums[i]) - 1] *= -1;
    } else {
      res[res_top] = __Abs(nums[i]);
      res_top++;
    }
  }
  *returnSize = res_top + 1;
  return res;
}

void Test() {
  int nums[8] = {4, 3, 2, 7, 8, 2, 3, 1};
  for (int i = 0; i < 8; i++) {
    printf("%d\n", nums[i]);
  }
  int returnSize;
  int *res = findDuplicates(&nums[0], 8, &returnSize);
  for (int i = 0; i < 2; i++) {
    printf("%d\n", res[i]);
  }
free(res);
}

int main(void)
{
  Test();
  return 0;
}
