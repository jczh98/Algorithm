/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include "utils.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> ret;
        ret.insert(ret.end(), nums1.begin(), nums1.end());
        ret.insert(ret.end(), nums2.begin(), nums2.end());
        std::sort(ret.begin(), ret.end());
        const int sz = ret.size();
        if (sz == 0) {
            return 0;
        }
        if (sz % 2 != 0) {
            return ret[sz/2];
        } else {
            return double(ret[sz/2] + ret[sz/2-1]) / 2;
        }
    }
};

int main() {
    Solution sol;
    std::vector<int> inputs1 = {1, 3}, inputs2 = {2};
    std::cout << sol.findMedianSortedArrays(inputs1, inputs2) << std::endl;;
}
// @lc code=end

