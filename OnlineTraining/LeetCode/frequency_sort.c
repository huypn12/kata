#include "stdafx.h"

char * frequencySort(char * s){
    size_t sLen = strlen(s);
    char *res = (char *) malloc(sLen * sizeof(char));
    
}

void test()
{
    char *res = NULL;

    res = frequencySort("tree");
    assert(!strcmp(res, "eert"));
    free(res);

    res = frequencySort("cccaaa");
    assert(!strcmp(res, "cccaaa"));
    free(res);

    res = frequencySort("Aabb");
    assert(!strcmp(res, "bbAa") || !strcmp(res, "bbaA"));
    free(res);
}

int main()
{
    test();

    return EXIT_SUCCESS;
}