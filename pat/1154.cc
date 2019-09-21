#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

vector<int> G[20000];
map<int, int> mp;
int n, m, k, col[20000], vis[20000];
bool flag;
void dfs(int u) {
    if (vis[u]) return;
    if (flag) return;
    vis[u] = 1;
    mp[col[u]]=1;
    for (int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if (col[u] == col[v]) flag = 1;
        if (flag) return;
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);G[v].push_back(u);
    }
    scanf("%d", &k);
    for (int q = 1; q <= k; ++q) {
        mp.clear();
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &col[i]);
        }
        flag = false;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        if (!flag && mp.size()>0) {
            printf("%d-coloring\n", mp.size());
        } else {
            printf("No\n");
        }
    }
    return 0;
}
