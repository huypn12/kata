#include "stdafx.h"

#define MAX_PPL 1001

int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int tblTrusts[MAX_PPL];
    memset(tblTrusts, 0x0, MAX_PPL);
    
    int tblTrustedBy[MAX_PPL];
    memset(tblTrustedBy, 0x0, MAX_PPL);
    
    for (int i = 0; i < trustSize; i++) {
        tblTrusts[trust[i][0]]++;
        tblTrustedBy[trust[i][1]]++;
    }
    
    int judge = -1;
    for (int i = 1; i <= N; i++) {
        if (tblTrustedBy[i] == N - 1) {
            if (judge == -1) judge = i;
            else return -1;
        }
    }
    if (judge == -1) {
        return -1;
    }
    
    if (tblTrustedBy[judge] == N - 1 && tblTrusts[judge] == 0)
        return judge;
        
    return -1;
}

void test()
{
    int N = 1;
    int trust[2][12] = {{0}};
}

int main()
{
    test();
}