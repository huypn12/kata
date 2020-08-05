# include "stdafx.h"

static inline int myStrlen(char *p)
{
    int len = 0;
    while (*p != '\0') {
        p++;
        len++;
    }
    return len;
}

#define ALPHABET_LEN 26

static inline bool isEqual(int *s, int *t, int len)
{
    for (int i = 0; i < len; i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }
    return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *findAnagrams(char *s, char *p, int *returnSize)
{
    int sLen = myStrlen(s);
    int pLen = myStrlen(p);
    if (sLen < pLen) {
        *returnSize = 0;
        return NULL;
    }
    
    int anagramCount = 0;
    int *anagramIdx = (int *) malloc(sizeof(int) * sLen);
    
    int countS[ALPHABET_LEN] = {0};
    int countP[ALPHABET_LEN] = {0};

    char offset = 'a';
    for (int i = 0; i < pLen; i++) {
        countS[s[i] - offset]++;
        countP[p[i] - offset]++;
    }

    for (int i = pLen; i < sLen; i++) {
        if (isEqual(countS, countP, ALPHABET_LEN)) {
            anagramIdx[anagramCount] = i - pLen;
            anagramCount++;
        }
        countS[s[i] - offset]++;
        countS[s[i - pLen] - offset]--;
    }
    if (isEqual(countS, countP, ALPHABET_LEN)) {
        anagramIdx[anagramCount] = sLen - pLen;
        anagramCount++;
    }

    *returnSize = anagramCount;
    int *result = NULL;
    if (anagramCount == 0) {
        free(anagramIdx);
        return result;
    }

    result = (int *) malloc(sizeof(int) * anagramCount);
    for (int i = 0; i < anagramCount; i++) {
        result[i] = anagramIdx[i];
    }
    free(anagramIdx);

    return result;
}
