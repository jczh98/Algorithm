#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 100005;
int head[N], nxt[M], to[M], cnt;
int dfn[N], low[N], sccno[N], dfs_ind, vis[N], scc_cnt;
int edg[M], asc[M], ans;
inline void init() {memset(head, -1, sizeof(head)); cnt = 0; scc_cnt = 0; dfs_ind = 1;}
inline void add(int u, int v) {to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;}
void tarjan(int u) {
    dfn[u] = dfs_ind++;
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if(dfn[v]) {
            if(dfn[v] < dfn[to[edg[u]]]) edg[u] = i;
        }else {
            asc[i] = 1; ++ans; tarjan(v); 
        }
    }
    if(edg[u]) {
        asc[edg[u]] = 1;
        ++ans;
    }
}
int t, n, m, u, v;
int main() {
    scanf("%d", &t);
    while(t--) {
        memset(edg, 0, sizeof(edg));
        memset(asc, 0, sizeof(asc));
        memset(dfn, 0, sizeof(dfn));
        init();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        ans = 0; dfn[0] = INT_MAX;
        tarjan(1);
        for(int i = 0; i < m; ++i) {
            if(ans < 2 * n && !asc[i]) {
                asc[i] = 1; ++ans;
            }
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = head[i]; ~j; j = nxt[j]) {
                if(!asc[j]) {
                    printf("%d %d\n", i, to[j]);
                }
            }
        }
    }
    return 0;
}