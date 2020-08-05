#include "stdafx.hh"

// TODO: blanagram

class Solution {
public:
  bool isBlanagram(const std::string &s1, const std::string &s2) {
    std::unordered_map<int, int> hash;
  }
};

int main(int argc, char **argv) {
  auto s = Solution();
  std::cout << s.isBlanagram(std::string("tangram"), std::string("anagram"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("tangram"), std::string("pangram"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("politely"), std::string("linotype"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("tangram"), std::string("anagrem"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("tangram"), std::string("aaagram"))
            << std::endl;
  std::cout << s.isBlanagram(std::string("silent"), std::string("listen"))
            << std::endl;
}
