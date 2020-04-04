#include "fib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ull _fib_topdown(int n, ull *dp)
{
    if (dp[n] > 0) {
        return dp[n];
    }
    if (n == 0) {
        dp[n] = 0;
        return dp[n];
    }
    if (n <= 2) {
        dp[n] = 1;
        return dp[n];
    }
    dp[n] = _fib_topdown(n - 1, dp) + _fib_topdown(n - 2, dp);
    return dp[n];
}

ull fib_topdown(int n)
{
    size_t dp_size = (n + 1) * sizeof(ull);
    ull *dp = (ull *) malloc(dp_size);
    if (dp == NULL) {
        return 0;
    }
    memset(dp, 0x0, dp_size);
    ull f = _fib_topdown(n, dp);

    free(dp);
    return f;
}

ull _fib_bottomup(int n, ull *dp)
{
    return n;
}

ull fib_bottomup(int n)
{
    size_t dp_size = (n + 1) * sizeof(ull);
    ull *dp = (ull *) malloc(dp_size);
    if (dp == NULL) {
        return 0;
    }
    memset(dp, 0x0, dp_size);
    ull f = _fib_bottomup(n, dp);

    free(dp);
    return f;
}

ull fib_binet(int n) 
{
}
