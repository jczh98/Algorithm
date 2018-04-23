#include <bits/stdc++.h>
using namespace std;
const int N = 200005, M = 200005;
int cnt, head[N], nxt[M], to[M];
inline void add(int u, int v) {to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;} 
int n, m, dp[N];
int dfs(int u) {
    if(~dp[u]) return dp[u];
    int ret, flag = 0;
    for(int i = head[u]; ~i; i = nxt[i]) {
        ret = dfs(to[i]) ^ 1; flag = 1;
    }
    if(!flag) return 0;
    return dp[u] = ret;
}
int main() {
    cnt = 0; memset(head, -1, sizeof(head));
    memset(dp, -1, sizeof(dp));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        int num, x; scanf("%d", &num);
        for(int j = 1; j <= num; ++j) {
            scanf("%d", &x); add(i, x);
        }
    }
    for(int i = 1; i <= n; ++i) {
        dfs(i);
    }
    for(int i = 1; i <= n; ++i) {
        cout << dp[i] << endl;
    }
    return 0;
}