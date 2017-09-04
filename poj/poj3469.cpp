//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define MAXN 300005
#define MAXM 5000005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;
struct Edge {
    int to, nxt, c;
}edge[MAXM];
int head[MAXN], cnt = 0;
int d[MAXN], cur[MAXN], pre[MAXN], gap[MAXN];
int source, sink, limit;
void Init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
inline void AddEdge(int u, int v, int c) {
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    edge[cnt].c = c;
    head[u] = cnt++;
}

void RevBfs() {
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
int ISAP() {
    memcpy(cur, head, sizeof(cur));
    RevBfs();
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

int n, m, x, y, cap, a, b;
int main() {
    scanf("%d%d", &n, &m);
    Init();
    source = 0; sink = n + 1; limit = sink + 1;
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        AddEdge(source, i, a); AddEdge(i, source, 0);
        AddEdge(i, sink, b); AddEdge(sink, i, 0);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &cap);
        AddEdge(x, y, cap);
        AddEdge(y, x, cap);
    }
    printf("%d\n", ISAP());
    return 0;
}

