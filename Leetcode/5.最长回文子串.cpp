/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        for (int ans = s.size(); ans >= 2; ans--) {
            for (int i = 0; i + ans <= s.size(); i++) { 
                bool flag = true;
                int ed = (i + ans - 1);
                //std::cout << ans << " " << i << " " << ed << std::endl;
                for (int j = i; j < i + ans / 2 ; j++) {
                    if (s[j] != s[ed - j + i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    std::string str;
                    for (int j = i; j < i + ans; j++) {
                        str += s[j];
                    }
                    return str;
                }
            }
        }
        std::string ret;
        return ret + s[0];
    }
};

int main() {
    std::string s = "aaa";
    Solution so;
    std::cout << so.longestPalindrome(s) << std::endl;
}



// @lc code=end
