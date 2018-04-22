#include <bits/stdc++.h>
#define MAXN 110
#define MAXM 2020
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct Edge {
    int to, nxt, c;
}edge[MAXM];
int head[MAXN], cnt = 0;
int d[MAXN], cur[MAXN], pre[MAXN], gap[MAXN];
int source, sink, limit;
void init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
inline void add_edge(int u, int v, int c) {
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    edge[cnt].c = c;
    head[u] = cnt++;
}

inline void add(int u, int v, int c) {
    add_edge(u, v, c); add_edge(v, u, 0);
}

void rev_bfs() {
    memset(gap, 0, sizeof(gap));
    memset(d, -1, sizeof(d));
    d[sink] = 0;
    gap[0] = 1;
    queue<int> que;
    que.push(sink);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(~d[v])continue;
            d[v] = d[u] + 1;
            gap[d[v]]++;
            que.push(v);
        }
    }
}
int isap() {
    memcpy(cur, head, sizeof(cur));
    rev_bfs();
    int flow = 0, i;
    int u = source;
    pre[source] = source;
    while(d[sink] < limit) {
        if(u == sink) {
            int f = inf, neck;
            for(i = source; i != sink; i = edge[cur[i]].to) {
                if(f > edge[cur[i]].c) {
                    f = edge[cur[i]].c;
                    neck = i;
                }
            }
            for(i = source; i != sink; i = edge[cur[i]].to) {
                edge[cur[i]].c -= f;
                edge[cur[i] ^ 1].c += f;
            }
            flow += f;
            u = neck;
        }
        for(i = cur[u]; ~i; i = edge[i].nxt) {
            if(d[edge[i].to] + 1 == d[u] && edge[i].c) break;
        }
        if(~i) {
            cur[u] = i;
            pre[edge[i].to] = u;
            u = edge[i].to;
        }else {
            if((--gap[d[u]]) == 0) break;
            int mind = limit;
            for(int i = head[u]; ~i; i = edge[i].nxt) {
                if(edge[i].c && mind > d[edge[i].to]) {
                    cur[u] = i;
                    mind = d[edge[i].to];
                }
            }
            d[u] = mind + 1;
            gap[d[u]]++;
            u = pre[u];
        }
    }
    return flow;
}
int n, m, u[505], v[505], val[505], ans;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) scanf("%d%d%d", &u[i], &v[i], &val[i]);
    for(int i = 1; i <= m; ++i) {
        init();
        for(int j = 1; j <= m; ++j) {
            if(i == j) continue;
            if(val[i] > val[j]) {
                add(u[j], v[j], 1); add(v[j], u[j], 1);
            }
        }
        source = u[i]; sink = v[i]; limit = n;
        ans += isap();
    }
    printf("%d\n", ans);
    return 0;
}