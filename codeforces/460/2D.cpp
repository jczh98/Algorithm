#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, m, x, y, f[300005][30], indeg[300005], ans, vis[300005];
char nodes[300005];
int head[300005], nxt[300005], to[300005], cnt = 0;
inline void add(int u, int v) {
    to[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}
void dfs(int u, int pre) {
    if(vis[u]) return;
    vis[u] = 1;
    for(int i = 0; i < 26; ++i) {
        f[u][i] = max(f[u][i], f[pre][i] + ((nodes[u] - 'a') == i));
    }
    for(int i = head[u]; ~i; i = nxt[i]) {
        dfs(to[i], u);
    }
}
bool check() {
    queue<int> que;
    for(int i = 1; i <= n; ++i) if(!indeg[i]) que.push(i), f[i][nodes[i] - 'a']++;
    int cnt = 0;
    while(!que.empty()) {
        int u = que.front(); que.pop(); cnt++;
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i];
            for(int j = 0; j < 26; ++j) {
                f[v][j] = max(f[v][j], f[u][j] + ((nodes[v] - 'a') == j));
            }
            indeg[v]--;
            if(!indeg[v]) que.push(v);
        }
    }
    if(cnt == n) return true; else return false;
}
int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    scanf("%s", nodes + 1);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y); indeg[y]++;
        add(x, y);
    }
    if(!check()) {printf("-1\n"); return 0;}
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 26; ++j) {
            ans = max(ans, f[i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}