#include "stdafx.hpp"

using namespace std;

class Solution {
public:
  string generateTheString(int n) {
    std::ostringstream result;
    int i = 0;
    while (n > 0) {
      int div = n / 2;
      int sub = 0;
      if (div % 2 == 0) {
        sub = div + 1;
      } else {
        sub = div;
      }
      result << string(sub, 'a' + i);
      i++;
      n -= sub;
    }
    return result.str();
  }
};

int main() {
  int n = 4;
  vector<int> letterCount;
  while (n > 0) {
    int div = n / 2;
    int sub = 0;
    if (div % 2 == 0) {
      sub = div + 1;
    } else {
      sub = div;
    }
    letterCount.push_back(sub);
    n -= sub;
  }
  for (auto const &it : letterCount) {
    std::cout << it << std::endl;
  }
}