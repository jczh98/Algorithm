#include <bits/stdc++.h>
using namespace std;
vector<int> G[100005];
int n;
double ans = 0.0;
void Dfs(int u, int fa, double last_p) {
    if(G[u].size() == 1 && u != 1) return ;
    double p;
    if(u == 1) {
        p = last_p * 1.0 / G[u].size();
    }else {
        p = last_p * 1.0 / (G[u].size() - 1);
    }
    //cout << u << " " << p << endl;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == fa) continue;
        ans += p;
        Dfs(v, u, p);
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    Dfs(1, 0, 1.0);
    printf("%.15f", ans);
    return 0;
}

