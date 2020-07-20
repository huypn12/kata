#include <stdio.h>
#include <stdlib.h>

void myStrcpy() {}

void *myMemSet(void *dst, int value, size_t len)
{
    for (char *it = (char *) dst; len--;)
        *it++ = value;
    return (dst);
}

int main()
{
    int *p = malloc(32 << 10);
    if (p == NULL) {
        return 1;
    }
    *p = 0xdeadbeef;
    printf("%x", p[0]);
    return 0;
}
