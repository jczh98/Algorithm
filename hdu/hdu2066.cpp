#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
typedef pair<int, int> pii;
const int N = 10005, M = 1000000;
int t, s, d, S[N], D[N];
int head[N], nxt[M], to[M], val[M], cnt;
inline void init() {cnt = 0; memset(head, -1, sizeof(head));}
inline void adde(int u, int v, int w) {to[cnt] = v; val[cnt] = w; nxt[cnt] = head[u]; head[u] = cnt++;}
inline void addb(int u, int v, int w) {adde(u, v, w); adde(v, u, w);}
int dis[N], vis[N];
inline void dijkstra(int s) {
    priority_queue<pii> pq;
    memset(vis, 0, sizeof(vis)); memset(dis, 127, sizeof(dis)); dis[s] = 0;
    pq.push(make_pair(dis[s], s));
    while(!pq.empty()) {
        int now = pq.top().second; pq.pop();
        vis[now] = 0;
        for(int i = head[now]; ~i; i = nxt[i]) {
            int v = to[i]; 
            if(dis[v] > dis[now] + val[i]) {
                dis[v] = dis[now] + val[i];
                if(!vis[v]) {
                    pq.push(make_pair(dis[v], v));
                    vis[v] = 1;
                }      
            }
        }
    }
}
int main() {
    while(scanf("%d%d%d", &t, &s, &d) != EOF) {
        init();
        for(int i = 1; i <= t; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w); addb(u, v, w);
        }
        for(int i = 1; i <= s; ++i) scanf("%d", &S[i]), addb(0, S[i], 0);
        for(int i = 1; i <= d; ++i) scanf("%d", &D[i]), addb(D[i], 1001, 0);
        dijkstra(0);
        printf("%d\n", dis[1001]);
    }
    return 0;
}