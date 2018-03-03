#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long LL;
typedef pair<LL, int> pli;
const int N = 200010;
int cnt, head[N], nxt[3 * N], to[3 * N];
LL val[3 * N];
inline void add_edge(int u, int v, LL w) {
    to[cnt] = v; val[cnt] = w; nxt[cnt] = head[u]; head[u] = cnt++;
}
int vis[N];
LL dis[N];
int n, m, x, y;
LL z;
inline void dijkstra(int s) {
    priority_queue<pli, vector<pli >, greater<pli > > pq;
    memset(vis, 0, sizeof(vis));
    memset(dis,0x3f,sizeof(dis)); dis[s] = 0;
    pq.push(make_pair(dis[s], s));
    while(!pq.empty()) {
        pli now = pq.top(); pq.pop();
        int u = now.second; if(vis[u]) continue; vis[u] = 1;
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[u] + val[i]) {
                dis[v] = dis[u] + val[i];
                pq.push(make_pair(dis[v], v));
            }
        }
    }
}
int main() {
    cnt = 0; memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%I64d", &x, &y, &z);
        add_edge(x, y, 2 * z); add_edge(y, x, 2 * z);
    }
    for(int i = 1; i <= n; ++i) {
        scanf("%I64d", &z);
        add_edge(0, i, z);
    }
    dijkstra(0);
    for(int i = 1; i <= n; ++i) {
        printf("%I64d%c", dis[i], i == n ? '\n' : ' ');
    }
    return 0;
}