#include "stdafx.h"

using namespace std;

class Solution {
public:
  int numTimesAllBlue(vector<int> &light) {
    int max = 0, head = 0, res = 0;
    for (auto const &it : light) {
        head++;     
      if (it > max)
        max = it;

      if (max == head) {
        res++;
      }
    }
    return res;
  }
};

int main() {
  auto s = Solution();
  auto testInput = std::vector<int>({2, 1, 3, 5, 4});
  // for (int i = 1; i <= 18295; i++) testInput.push_back(i);
  std::cout << s.numTimesAllBlue(testInput) << std::endl;
}
