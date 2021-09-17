/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include "utils.h"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        nums.push_back(std::numeric_limits<int>::min());
        while (l < r) {
            int mid = (l+r)>>1;
            if (nums[mid] > nums[mid + 1]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    Solution sol;
    std::vector<int> inputs = {1, 2, 1, 3, 5, 6, 4};
    std::cout << sol.findPeakElement(inputs);
}
// @lc code=end

