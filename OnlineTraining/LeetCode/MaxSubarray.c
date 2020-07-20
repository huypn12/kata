#include <stdio.h>

typedef long long int lli;


int solution(int A[], int N, int K, int L) {
  // write your code in C99 (gcc 6.2.0)
  if (K + L > N) {
    return -1;
  }

  lli max_sum = -1;

  for (int i = 0; i <= N - K; i++) {
    int alice_lower = i;
    int alice_upper = i + K - 1;
    lli alice_sum = 0;
    for (int alice_it = alice_lower; alice_it <= alice_upper; alice_it++) {
      alice_sum += A[alice_it];
    }

    for (int j = 0; j <= N - L; j++) {
      int bob_lower = j;
      int bob_upper = j + L - 1;
      lli bob_sum = 0;
      for (int bob_it = bob_lower; bob_it <= bob_upper; bob_it++) {
        bob_sum += A[bob_it];
      }
      if (!(/* not overlap */
            ((alice_lower < bob_lower) &&
             (alice_upper < bob_upper)) || /* alice before */
            ((alice_lower > bob_lower) &&
             (alice_upper > bob_upper)) || /* alice after */
            ((alice_lower > bob_lower) &&
             (alice_upper < bob_upper)) || /* bob contains alice */
            ((alice_lower < bob_lower) &&
             (alice_upper > bob_upper)) /* alice contains bob */
            )) {
        lli sum = bob_sum + alice_sum;
        if (sum > max_sum) {
          max_sum = sum;
        }
      }
    }
  }
  return max_sum;
}

int solution2(int A[], int N, int K, int L) {
    
}

int main() {
    int A[] = {6, 1, 4, 6, 3, 2, 7, 4};
    printf("%d\n", solution(A, 8, 3, 2));
    
    return 0;
}
