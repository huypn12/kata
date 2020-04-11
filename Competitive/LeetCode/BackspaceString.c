#include <stdio.h>

int backspaceCompare(char *S, char *T) {
  int lenS, lenT = 0;
  int it = 0;
  while (S[it] != '\0') {
    it++;
  }
  lenS = it;

  it = 0;
  while (T[it] != '\0') {
    it++;
  }
  lenT = it;

  int i = lenS - 1;
  int j = lenT - 1;
  while (i >= 0 && j >= 0) {
    printf("%d %d \n", i, j);
    int skipCount = 0;
    while (S[i] == '#') {
      skipCount++;
      i = i - skipCount - 1;
    }

    skipCount = 0;
    while (T[j] == '#') {
      skipCount++;
      T[--j] == '#' ? skipCount++ : skipCount--;
      
    }

    if (S[i] != T[j]) {
      printf("%d %d \n", i, j);
      return 1;
    }

    i--;
    j--;
  }

  return 0;
}

int testBackward() {}

int main() {
  /*
char S[] = "xywrrmp";
char T[] = "xywrrmu#p";
*/
  char S[] = "#a#c";
  char T[] = "a##c";
  printf("%d \n", backspaceCompare(S, T));
}