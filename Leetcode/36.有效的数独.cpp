/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include "utils.h"

class Solution {
 public:
  bool isValidSudoku(vector<vector<char> >& board) {
    bool ans = true;
    for (int i = 0; i < board.size(); i++) {
      int cnt[10] = {0};
      for (int j = 0; j < board[0].size(); j++) {
        if (std::isalnum(board[i][j])) {
          if (cnt[board[i][j]]) {
            ans = false;
            break;
          }
          cnt[board[i][j] - '0'] += 1;
        }
      }
      if (!ans) break;
    }
    for (int j = 0; j < board[0].size(); j++) {
      int cnt[10] = {0};
      for (int i = 0; i < board.size(); i++) {
        if (std::isalnum(board[i][j])) {
          if (cnt[board[i][j]]) {
            ans = false;
            break;
          }
          cnt[board[i][j] - '0'] += 1;
        }
      }
      if (!ans) break;
    }
    for (int i = 0; i < board.size(); i += 3) {
      for (int j = 0; j < board[0].size(); j += 3) {
        int cnt[10] = {0};
        for (int k1 = i; k1 < i + 3; k1++) {
          for (int k2 = j; k2 < j + 3; k2++) {
            if (std::isalnum(board[k1][k2])) {
              if (cnt[board[k1][k2]]) {
                ans = false;
                break;
              }
              cnt[board[k1][k2] - '0'] += 1;
            }
          }
        }
        if (!ans) break;
      }
      if (!ans) break;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<char> > board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  std::cout
      << sol.isValidSudoku(board)
      << std::endl;
}
// @lc code=end
