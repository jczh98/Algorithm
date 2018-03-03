#include <bits/stdc++.h>
#define MAXN 300005
#define MAXM 50000005
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
int t, n, m, k, w[100][100], x, y, z;
int get(int x, int y) {return (x - 1) * m + y;}
int main() {
    scanf("%d", &t);
    while(t--) {
        init();
        scanf("%d%d%d", &n, &m, &k);
        source = 0; sink = n * m + 1; limit = sink + 1;
        for(int i = 1; i <= n; ++i) {
            add(source, get(i, 1), inf);
            for(int j = 1; j <= m; ++j) {
                scanf("%d", &w[i][j]);
                if(j < m) add(get(i, j), get(i, j + 1), 1000 - w[i][j]);
                else add(get(i, j), sink, 1000 - w[i][j]);
            }
        }
        for(int i = 1; i <= k; ++i) {
            scanf("%d%d%d", &x, &y, &z);
            for(int j = 1; j <= m; ++j) {
                if(j - z < 1) add(get(x, j), source, inf);
                else if(j - z <= m) add(get(x, j), get(y, j - z), inf);
                else add(get(x, j), sink, inf);
            }
        }
        int ans = isap();
        if(ans >= inf) printf("-1\n"); else printf("%d\n", 1000 * n - ans);
    }
    return 0;
}