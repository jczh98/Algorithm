#include <bits/stdc++.h>
using namespace std;
int t, n, N, vis[10000], match[10000], ans, match_ans[2000];
vector<int> G[10000];
int Dfs(int x) {
    for(int i = 0; i < G[x].size(); i++) {
        int v = G[x][i];
        if(!vis[v]) {
            vis[v] = 1;
            if(match[v] == -1 || Dfs(match[v])) {
                match[v] = x;
                match_ans[x] = v;
                return true;
            }
        }
    }
    return false;
}

void Hungary() {
    ans = 0;
    memset(match, -1, sizeof match);
    for (int i = 1; i <= N; i++) {
        memset(vis, 0, sizeof vis);
        if (Dfs(i))ans++;
    }
}

map<int, int> mp, re_mp;
int x, cnt = 1;

int main() {
    scanf("%d", &n);
    N = 2 * n - 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &x);
            if (!mp[x]) {
                re_mp[cnt] = x;
                mp[x] = cnt++;
            }
            G[n - i + j].push_back(mp[x]);
        }
    }
    Hungary();
    if (ans == N) {
        cout << "YES";
        for (int i = 1; i <= N; i++) {
            cout << " " << re_mp[match_ans[i]];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}
