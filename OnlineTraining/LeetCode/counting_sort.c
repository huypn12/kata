/*
Counting sort is used in the case, input array has low range
for example, char
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * TODO
 */

int* CountingSort(int *base, int count, int range)
{
  int * = (int *) malloc(sizeof(int) * n);
  memset(arr, 0x0, n);
  for (int i = 0; i < n; i++) {
    count[arr[i]]++;
  }
  int total = 0;
  for (int i = 0; i < n; i++) {
    count[i] = total;
    total = count[i] + total;
  }
  int *sorted = (int *) malloc(sizeof(int) * n);
  memset(sorted, 0x0, n);
  for (int i = 0; i < n; i++) {
      count[arr[i]]++;
  }
}

int Test()
{
  
}
