#include <bits/stdc++.h>
#define MAXM 1000
#define MAXN 1000
#define inf 0x3f3f3f3f
using namespace std;
struct Edge {
    int to, nxt, c;
}edge[MAXM];
int head[MAXN], cnt = 1;
int d[MAXN], cur[MAXN], pre[MAXN], num[MAXN];
int source, sink, limit;
void AddEdge(int u, int v, int c) {
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    edge[cnt].c = c;
    head[u] = cnt ++;
}
void RevBfs() {
    memset(num, 0, sizeof(num));
    memset(d, -1, sizeof(d));
    d[sink] = 0;
    num[0] = 1;
    queue<int> que;
    que.push(sink);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(int i = head[u]; i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(~d[v])continue;
            d[v] = d[u] + 1;
            num[d[v]]++;
            que.push(v);
        }
    }
}
int ISAP() {
    memcpy(cur, head, sizeof(cur));
    RevBfs();
    int flow = 0;
    int u = source;
    pre[source] = source;
    while(d[sink] < limit) {
        if(u == sink) {
            int f = inf, neck;
            for(int i = source; i != sink; i = edge[cur[i]].to) {
                if(f > edge[cur[i]].c) {
                    f = edge[cur[i]].c;
                    neck = i;
                }
            }
            for(int i = source; i != sink; i = edge[cur[i]].to) {
                edge[cur[i]].c -= f;
                if(cur[i] & 1) edge[cur[i] + 1].c += f;
                else edge[cur[i] - 1].c += f;
            }
            flow += f;
            u = neck;
        }
        int i;
        for(i = cur[u]; i; i = edge[i].nxt) {
            if(d[edge[i].to] + 1 == d[u] && edge[i].c) break;
        }
        if(i) {
            cur[u] = i;
            pre[edge[i].to] = u;
            u = edge[i].to;
        }else {
            if((--num[d[u]]) == 0) break;
            int mind = limit;
            for(int i = head[u]; i; i = edge[i].nxt) {
                if(edge[i].c && mind > d[edge[i].to]) {
                    cur[u] = i;
                    mind = d[edge[i].to];
                }
            }
            d[u] = mind + 1;
            num[d[u]]++;
            u = pre[u];
        }
    }
    return flow;
}

int n, m, x, y, cap;
int main() {
    while(scanf("%d%d", &m, &n) != EOF ) {
        memset(head, 0, sizeof(head));
        cnt = 1;
        for(int i = 1; i <= m; i++) {
            scanf("%d%d%d", &x, &y, &cap);
            AddEdge(x, y, cap);
            AddEdge(y, x, 0);
        }
        source = 1; sink = n; limit = sink + 1;
        printf("%d\n", ISAP());
    }
    return 0;
}

