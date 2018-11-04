#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 2000005;
int to[M], nxt[M], head[N], cnt, dis1[N], dis2[N];
inline void add(int u, int v) {to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;}
void dfs(int x, int fa) {
    for(int i = head[x]; ~i; i = nxt[i]) {
        int v = to[i];
        if(v == fa) continue;
        dis1[v] = dis1[x] + 1; dfs(v, x);
    }
}
int t, n, m;
int main() {
    scanf("%d", &t);
    while(t--) {
        cnt = 0; memset(head, -1, sizeof(head));
        scanf("%d", &n);
        int u, v, x, k;
        for(int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            add(u, v); add(v, u);
        }
        v = 1; dis1[v] = 0; dfs(v, 0);
        for(int i = 1; i <= n; ++i) if(dis1[i] > dis1[v]) v = i;
        dis1[v] = 0; dfs(v, 0);
        for(int i = 1; i <= n; ++i) if(dis1[i] > dis1[v]) v = i;
        for(int i = 1; i <= n; ++i) dis2[i] = dis1[i];
        dis1[v] = 0; dfs(v, 0);
        scanf("%d", &m);
        while(m--) {
            scanf("%d%d", &x, &k);
            int d = max(dis1[x], dis2[x]);
            if(k <= d) printf("%d\n", k + 1);
            else printf("%d\n", min(n, d + 1 + (k - d) / 2));
        }
    }
    return 0;
}