#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, ans = 0, vis[200005], flag = 0;
vector<int> nodes[200005];
void dfs(int x) {
    vis[x] = 1;
    if(nodes[x].size() != 2) flag = 0;
    for(auto v : nodes[x]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        nodes[u].push_back(v); nodes[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            flag = 1;
            dfs(i);
            ans += flag;
        }
    }
    cout << ans << endl;
    return 0;
}