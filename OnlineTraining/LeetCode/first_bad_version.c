// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include "stdafx.h"

static int gBadVer = 0;

int isBadVersion(int v)
{
    // duhhh stupid, must implement RBtree here as a std::set
    // if (v == gBadVer) return 1;
} 

// skip list
// 2,1
int firstBadVersion(int n) {
    for (int i = 0; i <= (n / 2); i++) {
        int idx = i * 2;
        if (isBadVersion(idx)) return idx;
    }
    
    for (int i = 0; i <= (n / 2); i++) {
        int idx = i * 2 + 1;
        if (idx > n) break;
        if (isBadVersion(idx)) return idx;
    }
    
    // no bad version
    return -1;
}

