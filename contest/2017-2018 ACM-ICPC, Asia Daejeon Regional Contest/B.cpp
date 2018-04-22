#include <bits/stdc++.h>
using namespace std;
int x, a, b, g[10][10], ans;
int dx[4] = {1, 1, 0, 1};
int dy[4] = {1, -1, 1, 0};
map<int, int> state;
int hash_() {
    int ret = 0;
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 4; ++j) {
            ret = ret * 3 + g[i][j]; 
        }
    }
    return ret;
}
bool check(int x, int y) {
    int t = g[x][y];
    for(int i = 0; i < 4; ++i) {
        int nx = x, ny = y, cnt = 0;
        while(g[nx][ny] == t) {
            cnt++; nx += dx[i]; ny += dy[i];
        }
        nx = x; ny = y;
        while(g[nx][ny] == t) {
            cnt++; nx -= dx[i]; ny -= dy[i];
        }
        if(cnt - 1 >= 3) return true;
    }
    return false;
}
void print() {
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 4; ++j) {
            cout << g[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void dfs(int now) {
    for(int j = 1; j <= 4; ++j) {
        int i = 1;
        while(g[i][j]) i++;
        if(i > 4) continue;
        g[i][j] = now;
        int s = hash_();
        if(state.find(s) != state.end()) {
            g[i][j] = 0;
            continue;
        }
        if(check(i, j)) {
            if(now == 2 && i == a && j == b) {
                ans++; 
            }
            g[i][j] = 0; continue;
        }
        state[s] = 1;
        dfs(3 - now);   
        g[i][j] = 0;     
    }
}
int main() {
    scanf("%d%d%d", &x, &a, &b);
    g[1][x] = 1;
    dfs(2);
    cout << ans << endl;
    return 0;
}