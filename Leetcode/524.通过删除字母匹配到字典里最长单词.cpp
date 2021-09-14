/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        std::string ans;
        int cnt = 0;
        for (int i = 0; i < dictionary.size(); i++)
        {
            int idx = 0;
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == dictionary[i][idx])
                {
                    idx++;
                }
            }
            if (idx == dictionary[i].size())
            {
                if (dictionary[i].size() > cnt)
                {
                    cnt = dictionary[i].size();
                    ans = dictionary[i];
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution app;
    std::vector<std::string> dict{"ale", "apple", "monkey", "plea"};
    std::cout << app.findLongestWord("abpcplea", dict);
}
// @lc code=end
