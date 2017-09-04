#include <bits/stdc++.h>
using namespace std;
int dp[30][30][30][30];
char G[30][30];
int DFS(int x1, int y1, int x2, int y2) {
    if(x1 > x2 || y1 > y2) return 0;
    if(~dp[x1][y1][x2][y2]) return dp[x1][y1][x2][y2];
    set<int> S;
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            if(G[i][j] == 'X') continue;
            int sg = 0;
            sg ^= DFS(x1, y1, i - 1, j - 1);
            sg ^= DFS(i + 1, j + 1, x2, y2);
            sg ^= DFS(i + 1, y1, x2, j - 1);
            sg ^= DFS(x1, j + 1, i - 1, y2);
            S.insert(sg);
        }
    }
    int mex = 0;
    while(S.count(mex))mex++;
    return dp[x1][y1][x2][y2] = mex;
}
int n, m;
int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", G[i] + 1);
    }
    if(DFS(1, 1, n, m)) {
        printf("First\n");
    }else {
        printf("Second\n");
    }
    return 0;
}

