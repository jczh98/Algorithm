#include <stdio.h>
#include <string.h>

int n, m, k;
int G[1005][1005];
int vis[1005], cnt;
void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    for(int i = 1; i <= n; ++i) {
        if (G[u][i] == 1) {
            dfs(i);
        }
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    for (int q = 1; q <= k; ++q) {
        int qq;
        scanf("%d", &qq);
        memset(vis, 0, sizeof(vis));
        vis[qq] = 1;
        cnt = 0;
        for (int i = 1; i <= n; ++i) {
            if (i != qq) {
                if (vis[i] == 0) {
                    dfs(i);
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt-1);
    }
    return 0;
}
