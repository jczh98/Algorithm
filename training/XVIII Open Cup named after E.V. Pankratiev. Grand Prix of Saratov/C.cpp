#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
#define MAXN 500001
using namespace std;
int n, m, ans[MAXN];
vector<int> vec[MAXN], ansv;
set<int> path[MAXN];
void dfs(int u, int fa) {
    for(int i = 0; i < vec[u].size(); ++i) {
        int v = vec[u][i]; if(v == fa) continue;
        dfs(v, u);
        if(path[u].size() < path[v].size()) swap(path[u], path[v]);
        for(int j : path[v]) {
            if(path[u].find(j) != path[u].end()) {
                ans[u] = 1; break;
            }else {
                path[u].insert(j);
            }
        }
    }
    if(ans[u]) path[u].clear();
}
int u, v;
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        vec[u].push_back(v); 
        vec[v].push_back(u); 
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &u, &v);
        if(u == v) {
            ans[u] = 1; continue;
        }
        path[u].insert(i); path[v].insert(i);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i) {
        if(ans[i]) ansv.push_back(i);
    }
    cout << ansv.size() << endl;
    for(int i = 0; i < ansv.size(); ++i) {
        cout << ansv[i];
        if(i == ansv.size() - 1) cout << endl; else cout << " ";
    }
    return 0;
}