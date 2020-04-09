#include "stdafx.h"

class Solution {
public:
  bool isBlanagram(const std::string &s1, const std::string &s2) {
    std::unordered_set concat = s1 + s2;
    int xorHash = 0x0;
    for (auto const &c : concat) {
      xorHash ^= c;
    }
    return (xorHash != 0x0);
  }
};

int main(int argc, char **argv) {
  auto s = Solution();
  std::cout << s.isBlanagram(std::string("tangram"), std::string("anagram"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("tangram"), std::string("pangram"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("POLITELY"), std::string("LINOTYPE"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("tangram"), std::string("anagrem"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("tangram"), std::string("aaagram"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("silent"), std::string("listen"))
            << std::endl;
}