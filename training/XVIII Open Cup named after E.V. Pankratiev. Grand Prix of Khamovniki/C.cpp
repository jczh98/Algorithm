#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 10005;
int n, m, u[M], v[M], deg[N], con[N];
int head[N], nxt[2 * M], to[2 * M], cnt = 0;
int link[N], vis[N];
inline void init() {memset(head, -1, sizeof(head)); cnt = 0;}
inline void add(int u, int v) {to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;}
int dfs(int x) {
    for(int i = head[x]; ~i; i = nxt[i]) {
        int v = to[i]; if(!vis[v]) {
            vis[v] = 1; if(!link[v] || dfs(link[v])) {
                link[v] = x; return 1;
            }
        }
    }
    return 0;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        deg[u[i]]++;deg[v[i]]++;
    }
    for(int i = 1; i <= n; ++i) {
        init();
        memset(con, 0, sizeof(con));
        memset(link, 0, sizeof(link));
        if(deg[i] >= n / 2) {
            for(int j = 1; j <= m; ++j) {
                if(u[j] == i) con[v[j]] = 1;
                if(v[j] == i) con[u[j]] = 1;
            }
            for(int j = 1; j <= m; ++j) {
                if((u[j] != i && !con[u[j]] && con[v[j]]) || (v[j] != i && !con[v[j]] && con[u[j]])) {
                    add(u[j], v[j]); add(v[j], u[j]);
                }
            }
            int match = 0, tot = 0;
            for(int j = 1; j <= n; ++j) {
                if(j == i || con[j]) continue;
                memset(vis, 0, sizeof(vis)); tot++;
                if(dfs(j)) match++;
            }
            if(match != tot) continue;
            printf("Yes\n");
            int cnt = 0;
            for(int j = 1; j <= n; ++j) if(con[j]) cnt++;
            printf("%d %d\n", i, cnt);
            for(int j = 1; j <= n; ++j) {
                if(con[j]) {
                    printf("%d %d\n", j, link[j] == 0 ? -1 : link[j]);
                }
            }
            return 0;
        }
    }
    printf("No\n");
    return 0;
}
/* 
5 4
1 2 
2 3 
3 4 
4 5

4 4
1 2 
2 3 
3 4 
4 1

4 3 
1 2 
2 3 
3 1
 */