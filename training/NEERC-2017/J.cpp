#include <bits/stdc++.h>
#define inf (1LL << 60)
using namespace std;
typedef long long ll;
const int N = 3005, M = 200005;
int n, m, k, u[M], v[M], w[M];
int head[N], nxt[M], to[M], val[M], cnt, vis[N];
ll dis[N];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
inline void init() {memset(head, -1, sizeof(head));cnt = 0;}
inline void add(int u, int v, int w) {to[cnt] = v; val[cnt] = w; nxt[cnt] = head[u]; head[u] = cnt++;}
inline ll dijkstra(int x) {
    //memset(vis, 0, sizeof(vis));
    for(register int i = 1; i <= n; ++i) dis[i] = inf;
    dis[1] = 0; pq.push(make_pair(dis[1], 1));
    while(!pq.empty()) {
        //int now = pq.top().second; 
        pair<ll,int> t = pq.top(); pq.pop();
        int now = t.second;
        // pq.pop();
        // if(vis[now]) continue; vis[now] = 1;
        if(dis[now] < t.first) {
            continue;
        }
        for(register int i = head[now]; ~i; i = nxt[i]) {
            int vv = to[i], ww = max(val[i] - x, 0);
            if(dis[vv] > t.first + 1LL * ww) {
                dis[vv] = t.first + 1LL * ww;
                pq.push(make_pair(dis[vv], vv));
            }
        }
    }
    return dis[n];
}
int main() {
    init();
    scanf("%d%d%d", &n, &m, &k);
    for(register int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        add(u[i], v[i], w[i]); add(v[i], u[i], w[i]);
    }
    ll ans = dijkstra(0);
    for(register int i = 1; i <= m; ++i) {
        ans = min(ans, dijkstra(w[i]) + 1LL * k * w[i]);
    }
    printf("%lld\n", ans);
    return 0;
}