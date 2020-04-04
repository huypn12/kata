/*
  Dr. Patel has N stacks of plates.
  .... Each stack contains K plates.
  .... Each plates has a positive beauty values

  Dr. Patel would like to take exactly P plates.
  ....If he take a plate in a stack,
  ........he must take all of the plates above it in the stack.

  Helps dr Patel pick the P plates that would maximize the total sum of beauty values

  Input:
  T // number of test cases
  N, K, P
  v11, v12, v13, ..., v1k  // beauty value of stack i
  ...
  vk1, vk2, vk3, ..., vkk
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct plates
{
    int N, K, P;
    int **values;
};

void destroy_plates(struct plates *p)
{
    if (p == NULL) {
        return;
    }
    if (p->values == NULL) {
        free(p);
        return;
    }
    for (int i = 0; i < p->K; i++) {
        if (p->values[i] == NULL) {
            continue;
        }
        free(p->values[i]);
    }
    free(p);
}

struct plates *create_plates(int N, int K, int P)
{
    struct plates *p = (struct plates *) malloc(sizeof(struct plates));
    if (p == NULL) {
        return NULL;
    }
    p->N = N;
    p->K = K;
    p->P = P;

    p->values = (int **) malloc(N * sizeof(int *));
    if (p->values == NULL) {
        return NULL;
    }
    for (int i = 0; i < N; i++) {
        p->values[i] = NULL;
    }

    for (int i = 0; i < N; i++) {
        p->values[i] = (int *) malloc(K * sizeof(int));
        if (p->values[i] == NULL) {
            destroy_plates(p);
            return NULL;
        }
        for (int j = 0; j < K; j++) {
            p->values[i][j] = 0;
        }
    }

    return p;
}

/*
  Dynamic programming:
  1. 
*/
int solve(const struct plates *p)
{
    size_t dp_size = ((p->N * p->K + 1) * (p->K + 1)) * sizeof(int);
    int *dp = (int *) malloc(dp_size);
    if (dp == NULL) {
        return -1;
    }
    // init to -Inf
    memset(dp, 0xc0, dp_size);

    int res = 0;
    return res;
}

int main()
{
    return EXIT_SUCCESS;
}
