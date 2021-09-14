/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <set>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int result = 0, cnt = 0;
        std::set<char> maps;
        for (int i = 0; i < s.size(); i++)
        {
            maps.clear();
            cnt = 0;
            for (int j = i; j < s.size(); j++) {
                auto it = maps.find(s[j]);
                if (it != maps.end()) {
                    result = std::max(cnt, result);
                    break;
                }
                maps.insert(s[j]);
                cnt++;
            }
            result = std::max(cnt, result);
        }
        return result;
    }
};
// @lc code=end
