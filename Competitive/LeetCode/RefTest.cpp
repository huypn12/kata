#include "stdafx.h"

int foo(std::string &S, std::string &T)
{
    auto strs = {&S, &T};
    for (std::string *s: strs) {
        char c = 'x';
        s->push_back(c);     
    }

    return 0;
}

int main() {
    auto S = std::string("aaa");
    auto T = std::string("bbb");
    foo(S, T);
    std::cout << S << " " << T << std::endl;
    return 0;
}