/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <algorithm>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int res = target - nums[i];
            auto it = std::find(nums.begin() + i + 1, nums.end(), res);
            if (it != nums.end())
            {
                return {i, static_cast<int>(std::distance(nums.begin(), it))};
            }
        }
        return {};
    }
};
// @lc code=end
