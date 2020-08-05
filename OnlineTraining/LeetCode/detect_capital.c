/*
 * Detect capital
 */
#include "stdafx.h"

#define SYM_COUNT 3
#define SYM_U 0
#define SYM_L 1
#define SYM_E 2

#define STATE_COUNT 6
#define STATE_ACCEPT 5
#define STATE_REJECT 4


int g_fsm[STATE_COUNT][SYM_COUNT] = {
    {1, 2, STATE_ACCEPT},
    {3, 2, STATE_ACCEPT},
    {STATE_REJECT, 2, STATE_ACCEPT},
    {3, STATE_REJECT, STATE_ACCEPT},
    {STATE_REJECT, STATE_REJECT, STATE_REJECT},
    {STATE_ACCEPT, STATE_ACCEPT, STATE_ACCEPT}};

int g_state;

static inline int ToFsmSym(char c) {
  if (c == '\0') {
    return SYM_E;
  } else if ('A' <= c && c <= 'Z') {
    return SYM_U;
  } else {
    return SYM_L;
  }
}

void RunFsm(char sym) {
  g_state = g_fsm[g_state][sym];
}

bool detectCapitalUse(char *word)
{
  g_state = 0;
  char *c = word;
  while (1) {
    RunFsm(ToFsmSym(*c));
    if (g_state == STATE_ACCEPT) {
      return true;
    } else if (g_state == STATE_REJECT) {
      return false;
    } else {
      c++;
    }
  }
}

void Test() {
  char *s = "ABC";
  assert(detectCapitalUse(s) == true);
  s = "";
  assert(detectCapitalUse(s) == true);
  s = "Abc";
  assert(detectCapitalUse(s) == true);
  s = "abc";
  assert(detectCapitalUse(s) == true);
  s = "ABc";
  printf("\n");
  assert(detectCapitalUse(s) == false);
  s = "AbC";
  assert(detectCapitalUse(s) == false);
  s = "abC";
  assert(detectCapitalUse(s) == false);
}

int main(void)
{
  Test();
}
