#include "stdafx.h"
#include <vector>

int foo(std::string &S, std::string &T)
{
    auto strs = {&S, &T};
    for (std::string *s : strs) {
        char c = 'x';
        s->push_back(c);
    }

    return 0;
}

int main()
{
    auto S = std::string("aaa");
    auto T = std::string("bbb");
    foo(S, T);
    std::cout << S << " " << T << std::endl;

    int t = 5;
    auto v = std::vector<int>(4, t);
    t = 8;
    PrintVector(v);
    return 0;
}
