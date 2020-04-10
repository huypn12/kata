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

  for (int i = 0, ii = 0; i < lenS; i++) {
    if (S[i] != '#') {
      ii = i;
    } else {
      S[i] = -1;
      while (S[ii] == -1)
        ii--;
      if (ii >= 0)
        S[ii] = -1;
    }
  }

  for (int i = 0, ii = 0; i < lenT; i++) {
    if (T[i] != '#') {
      ii = i;
    } else {
      T[i] = -1;
      while (T[ii] == -1)
        ii--;
      if (ii >= 0)
        T[ii] = -1;
    }
  }

  int i = 0, j = 0;
  while (i < lenS && j < lenT) {
    while (S[i] == -1) {
      i++;
    }
    while (T[j] == -1) {
      j++;
    }
    if (S[i] != T[j]) {
      return 1;
    }
    i++;
    j++;
  }

  return 0;
}

int main() {
    /*
  char S[] = "xywrrmp";
  char T[] = "xywrrmu#p";
  */
    char S[] = "#a#c";
  char T[] = "a##c";
  printf("%d \n", backspaceCompare(S, T));
}