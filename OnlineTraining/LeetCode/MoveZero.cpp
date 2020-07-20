#include "stdafx.h"

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    std::fill(std::remove(nums.begin(), nums.end(), 0), nums.end(), 0);
  }
};

int main() {
  auto s = Solution();
  auto testInput = std::vector<int>({0, 1, 0, 3, 12});
  s.moveZeroes(testInput);
  PrintVector(testInput);
}