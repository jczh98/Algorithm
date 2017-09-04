#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector <pii> G[300005];
vector <int> ans;
int n, m, u, v, d[300005], vis[300005], exist_neg = 0, sum = 0, edge_in[300005];
void DFS(int u, int id) {
    vis[u] = 1;
    int deg = 0;
    for(int i = 0; i < G[u].size(); i++) {
        pii v = G[u][i];
        if(vis[v.first]) continue;
        DFS(v.first, v.second);
        if(edge_in[v.second]) {
            deg ^= 1;
        }
    }
    if(d[u] == -1 || deg == d[u]) return;
    edge_in[id] = 1;
    if(id) {
        ans.push_back(id);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &d[i]);
        sum += d[i];
        if(d[i] == -1) {
            exist_neg = i;
        }
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(make_pair(v, i));
        G[v].push_back(make_pair(u, i));
    }
    if(exist_neg) {
        DFS(exist_neg, 0);
    }else if(sum % 2) {
        printf("-1\n");
        return 0;
    }else {
        DFS(1, 0);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}