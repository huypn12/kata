#include "stdafx.hpp"

class Solution {
private:
    int sumDigit(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
public:

    bool isHappy(int n) {
       std::unordered_set<int> dup;
        while (n > 1) {
            n = sumDigit(n);
            if (dup.find(n) != dup.end()) {
                return false;
            }
            dup.insert(n);
        }
        return true;
    }
};

int main(int argc, char ** argv)
{
    auto s = Solution();
    std::cout << s.isHappy(std::stoi(argv[1])) << std::endl;
}