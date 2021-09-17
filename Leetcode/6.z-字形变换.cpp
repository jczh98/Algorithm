/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start

#include "utils.h"

class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<std::string> rows(numRows);
        if (numRows == 1) {
            return s;
        }
        int row_idx = 0, row_dir = 0;;
        for (int i = 0;i < s.size(); i++) {
            rows[row_idx] += s[i];
            if (row_idx >= numRows - 1 || row_idx <= 0) {
                row_dir ^= 1;  
            }
            row_idx += row_dir ? 1 : -1;
        }
        std::string ans;
        for (auto row : rows) ans += row;
        return ans;
    }
};

int main() {
    Solution sol;
    //std::cout << sol.convert("PAYPALISHIRING", 3) << std::endl;
    std::cout << sol.convert("AB", 1) << std::endl;
}
// @lc code=end

