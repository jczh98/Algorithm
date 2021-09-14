/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            if (ans > std::numeric_limits<int>::max() / 10 || ans < std::numeric_limits<int>::min() / 10) {
                return 0;
            }
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    std::cout << sol.reverse(0) << std::endl;
}
// @lc code=end

