/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
#include "utils.h"

struct Tries {
  static const int N = 1000000;
  int nxt[N][26], end[N], root, sz;
  int newnode() {
    for (int i = 0; i < 26; i++) nxt[sz][i] = -1;
    end[sz++] = 0;
    return sz - 1;
  }
  void init() {
    sz = 0;
    root = newnode();
  }
  void insert(const char* buf, int id) {
    int len = strlen(buf);
    int now = root;
    for (int i = 0; i < len; i++) {
      if (nxt[now][buf[i] - 'a'] == -1)
        nxt[now][buf[i] - 'a'] = newnode();
      now = nxt[now][buf[i] - 'a'];
    }
    end[now] = id;
  }

  bool query(std::string str) {
    int now = root;
    for (int i = 0; i < str.size(); i++) {
      if (nxt[now][str[i] - 'a'] == -1) return false;
      now = nxt[now][str[i] - 'a'];
    }
    return true;
  }
} trie;

class Solution {
 public:
  const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
  int vis[20][20] = {0};
  int idx = 0;
  int h = 0, w = 0;
  std::vector<std::string> ans;

  void DFS(std::vector<std::vector<char> >& board, std::string path, int i, int j, int now) {
    if (now == -1) return;
    //std::cout << path << std::endl;
    if (trie.end[now]) {
      ans.push_back(path);
      trie.end[now] = 0;
      //std::cout << path << std::endl;
    }
    for (int d = 0; d < 4; d++) {
      if (i + dx[d] >= 0 && i + dx[d] < w && j + dy[d] >= 0 && j + dy[d] < h && !trie.end[now]) {
        if (vis[i + dx[d]][j + dy[d]]) continue;
        vis[i + dx[d]][j + dy[d]] = 1;
        std::string nxtstr = path + board[i + dx[d]][j + dy[d]];
        DFS(board, nxtstr, i + dx[d], j + dy[d], trie.nxt[now][board[i + dx[d]][j + dy[d]] - 'a']);
        vis[i + dx[d]][j + dy[d]] = 0;
      }
    }
  }
  vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    h = board[0].size();
    w = board.size();
    trie.init();
    for (int i = 0; i < words.size(); i++) {
      trie.insert(words[i].c_str(), i + 1);
    }
    for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++) {
        vis[i][j] = 1;
        std::string cur = "";
        cur += board[i][j];
        DFS(board, cur, i, j, trie.nxt[trie.root][board[i][j] - 'a']);
        vis[i][j] = 0;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  std::vector<std::vector<char> > board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
  std::vector<std::string> words = {"oath", "pea", "eat", "rain", "oathi", "oathk", "oathf", "oate", "oathii", "oathfi", "oathfii"};
  // std::vector<std::vector<char> > board;
  // for (int i = 0; i < 12; i++) {
  //   std::vector<char> ss;
  //   for (int j = 0; j < 12; j++) ss.push_back('a');
  //   board.push_back(ss);
  // }
  // std::vector<std::string> words = {"aaa", "pea", "eat", "rain"};
  std::cout << to_string(sol.findWords(board, words)) << std::endl;
}
// @lc code=end
