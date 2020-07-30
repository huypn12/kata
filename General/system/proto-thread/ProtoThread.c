#include <setjmp.h>

struct ProtoThread {
    int id;
    int pos;
    jmp_buf ctx;
    void (*funcPtr)();
};


