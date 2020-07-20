#include "stdafx.hpp"

class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    auto N = prices.size();
    int profit = 0;
    for (int i = 1; i < N; i++) {
      if (prices[i - 1] < prices[i]) {
        profit += prices[i] - prices[i - 1];
      }
    }
    return profit;
  }
};

int main() {
  auto s = Solution();
  auto testInput = std::vector<int>({7, 1, 5, 3, 6, 4});
  std::cout << s.maxProfit(testInput) << std::endl;

  testInput = std::vector<int>({1, 2, 3, 4, 5});
  std::cout << s.maxProfit(testInput) << std::endl;

  testInput = std::vector<int>({7, 6, 4, 3, 1});
  std::cout << s.maxProfit(testInput) << std::endl;

  testInput = std::vector<int>({6, 1, 3, 2, 4, 7});
  std::cout << s.maxProfit(testInput) << std::endl;

  testInput = std::vector<int>({2, 4, 1});
  std::cout << s.maxProfit(testInput) << std::endl;
}