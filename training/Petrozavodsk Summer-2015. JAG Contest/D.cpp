#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long LL;
LL n, m, s[2005], u, v, c, cost = 0;
struct Edge{
    LL to, nxt, c;
}edge[2005 * 2];
vector<LL> ans;
int head[2005], cnt = 0;
inline void Init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
inline void AddEdge(LL u, LL v, LL c) {
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    edge[cnt].c = c;
    head[u] = cnt++;
}
LL DFS(LL u, LL pre, LL root) {
    vector<LL> dis;
    for(LL i = head[u]; ~i; i = edge[i].nxt) {
        LL v = edge[i].to;
        if(v == pre) continue;
        dis.push_back(DFS(v, u, root) + edge[i].c * s[root]);
    }
    sort(dis.begin(), dis.end(), greater<LL>());
    for(int i = 1; i < dis.size(); i++) {
        ans.push_back(dis[i]);
    }
    if(dis.size() == 0) return 0;
    else return dis[0];
}
int main() {
    cin >> n >> m;
    Init();
    for(int i = 1; i < n; i++) {
        cin >> u >> v >> c;
        AddEdge(u, v, c);
        AddEdge(v, u, c);
    }
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++) {
        ans.push_back(DFS(i, 0, i));
    }
    sort(ans.begin(), ans.end(), greater<LL>());
    for(int i = 0; i < ans.size() && i < m; i++) {
        //cout << ans[i] << endl;
        cost += ans[i];
    }
    cout << cost << endl;
    return 0;
}

