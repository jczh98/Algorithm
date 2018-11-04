#include <bits/stdc++.h>
#define inf 1LL << 36
using namespace std;
typedef long long LL;
const int N = 100100;
int n, m, u[N], v[N], w[N], spt[N];
struct Dijk {
    int head[N], to[N * 2], nxt[N * 2], val[N * 2], cnt = 0;
    LL dis[N];
    inline void init() {cnt = 0; memset(head, -1, sizeof(head));}
    inline void add(int u, int v, int w) {
        to[cnt] = v; val[cnt] = w; nxt[cnt] = head[u]; head[u] = cnt++;
    }
    inline void dijkstra(int s) {
        priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL,int>> > pq;
        for(int i = 1; i <= n; ++i) dis[i] = inf;
        dis[s] = 0; pq.push(make_pair(dis[s], s));
        while(!pq.empty()) {
            int u = pq.top().second; pq.pop();
            for(int i = head[u]; ~i; i = nxt[i]) {
                int v = to[i];
                if(dis[v] > dis[u] + 1LL * val[i]) {
                    dis[v] = dis[u] + 1LL * val[i];
                    pq.push(make_pair(dis[v], v));
                }
            }
        }
    }
} A, B;
struct DAG {
    const int MOD = 1e9+7;
    int head[N], to[N * 2], nxt[N * 2], cnt = 0, vis[N], f[N];
    inline void init() {cnt = 0; memset(head, -1, sizeof(head));}
    inline void add(int u, int v) {
        to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;
    }
    int dfs(int x) {
        if(vis[x]) return f[x];
        vis[x] = 1;
        for(int i = head[x]; ~i; i = nxt[i]) {
            int v = to[i];
            f[x] = (f[x] + dfs(v)) % MOD;
        }
        return f[x];
    }
    inline void work(int s) {
        f[s] = 1; vis[s] = 1;
        for(int i = 1; i <= n; ++i) dfs(i);
    }
} C, D;
int main() {
    A.init(); B.init(); C.init(); D.init();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        A.add(u[i], v[i], w[i]); B.add(v[i], u[i], w[i]);
    }
    A.dijkstra(1); B.dijkstra(2);
    LL sp = A.dis[2];
    for(int i = 1; i <= m; ++i) {
        if(A.dis[u[i]] + 1LL * w[i] + B.dis[v[i]] == sp) {
            spt[i] = 1;
            C.add(v[i], u[i]); D.add(u[i], v[i]);
        }
    }
    C.work(1); D.work(2);
    int tot = C.f[2];
    for(int i = 1; i <= m; ++i) {
        if(spt[i]) {
            if(1LL * C.f[u[i]] * D.f[v[i]] % C.MOD == tot) printf("SAD\n");
            else printf("SOSO\n");
        }else {
            if(A.dis[v[i]] + 1LL * w[i] + B.dis[u[i]] < sp) printf("HAPPY\n");
            else printf("SOSO\n");
        }
    }
    return 0;
}