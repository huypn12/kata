#include "stdafx.h"
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        auto stkS = std::string();
        for (const auto &c : S) {
            if (c == '#') {
                if (!stkS.empty()) stkS.pop_back();
            } else {
                stkS.push_back(c);
            }
        }
        auto stkT = std::string();
        for (const auto &c : T) {
            if (c == '#') {
                if (!stkT.empty()) stkT.pop_back();
            } else {
                stkT.push_back(c);
            }
        }
        
        return stkS == stkT;
    }
};


int main() {
  auto s = Solution();
  cout << s.backspaceCompare(string("ab#c"), string("ad#c")) << std::endl;
  cout << s.backspaceCompare(string("a##c"), string("#a#c")) << std::endl;
cout << s.backspaceCompare(string("xywrrmp"), string("xywrrmu#p")) << std::endl;
cout << s.backspaceCompare(string("btoo#ab##c##bwab##"), string("btx#abc##a##w")) << std::endl;
}