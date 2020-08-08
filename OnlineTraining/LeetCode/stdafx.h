#pragma once

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  My datastructure implementation
*/

#define PrintArray(fmt, arr, n)                                                \
  {                                                                            \
    printf("[ ");                                                              \
    for (int i = 0; i < n; i++) {                                              \
      printf("%##fmt", arr[i]);                                                \
    }                                                                          \
    printf(" ]");                                                              \
  }

#define PrintArray2D(fmt, arr, m, n)                                           \
  {                                                                            \
    printf("[\n");                                                             \
    for (int i = 0; i < m; i++) {                                              \
      printf("\t");                                                            \
      PrintArray(fmt, array[i])                                                \
    }                                                                          \
    printf("]\n");                                                             \
  }
