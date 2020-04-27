#include "stdafx.hpp"

using namespace std;

class Solution {
public:
  using li = long int;

  li hashString(const string &s) {
    int xOr = 0, sum = 0;
    for (auto const &c : s) {
      sum |= 1 << (c - 32);
      xOr ^= c;
   }
   li res = xOr;
   res = res << 32;
   res |= sum;
    return res;
  }

public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<li, vector<string>> hashMap;
    for (auto &s : strs) {
      auto hashVal = hashString(s);
      auto grp = hashMap.find(hashVal);
      if (grp == hashMap.end()) {
        hashMap.insert(make_pair(hashVal, vector<string>({s})));
      } else {
        grp->second.push_back(s);
      }
    }
    auto result = vector<vector<string>>();
    for (auto kv : hashMap) {
      result.push_back(kv.second);
    }
    return result;
  }
};

int main() {
  auto s = Solution();
  auto testInput = vector<string>({"eat", "tea", "tan", "ate", "nat", "bat"});
  auto res = s.groupAnagrams(testInput);
  for (auto &v : res) {
    PrintVector(v);
  }
  testInput = vector<string>({"tao", "pit", "cam", "aid", "pro", "dog"});
  res = s.groupAnagrams(testInput);
  for (auto &v : res) {
    PrintVector(v);
  }

  testInput = vector<string>({"tao", "pit", "cam", "aid", "pro",
                              "dog"
                              "cab",
                              "tin", "pew", "duh", "may", "ill", "buy", "bar",
                              "max", "doc"});
  res = s.groupAnagrams(testInput);
  for (auto &v : res) {
    PrintVector(v);
  }
  std::cout << std::hex << s.hashString(std::string("fat")) << std::endl;
  std::cout << std::hex << s.hashString(std::string("red")) << std::endl;
}