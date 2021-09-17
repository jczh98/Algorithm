/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include "utils.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        std::vector<int> nums;
        while(x) {
            nums.emplace_back(x%10);
            x /= 10;
        }
        for (int i = 0; i < nums.size() / 2; i++) {
            if (nums[i] != nums[nums.size() - i -1]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    std::cout << sol.isPalindrome(1221) << std::endl;
}
// @lc code=end

