#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  My datastructure implementation
*/

#define PrintArry(fmt, arr, n) \
    { \
        printf("[ "); \
        for (int i = 0; i < n; i++) { \
            printf("%##fmt", arr[i]); \
        } \
    }