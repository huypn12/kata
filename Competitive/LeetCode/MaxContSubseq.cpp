
#include "stdafx.h"

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max = 1 << (sizeof(int)*8 - 1);
        int currentMax = 0;
        for (auto &it : nums) {
            currentMax += it;
            if (currentMax > max) {
                max = currentMax;
            }
            if (currentMax < 0) {
                currentMax = 0;
            }
        }
        return max;
    }
};

int main() {
  auto s = Solution();
  auto testInput = std::vector<int>({-2,1,-3,4,-1,2,1,-5,4});
  std::cout << s.maxSubArray(testInput) << std::endl;
}