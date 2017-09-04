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

int t, h, w, di, f, b, cost;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char mp[100][100];
int Get(int x, int y) {
    return (x - 1) * w + y;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        Init();
        cost = 0;
        scanf("%d%d", &w, &h);
        source = 0; sink = h * w + 1; limit = sink + 1;
        scanf("%d%d%d", &di, &f, &b);
        for(int i = 1; i <= h; i++) {
            scanf("%s", mp[i] + 1);
        }
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                if(i == 1 || i == h || j == 1 || j == w) {
                    if(mp[i][j] == '.') cost += f;
                    AddEdge(source, Get(i, j), inf);AddEdge(Get(i, j), source, 0);
                }else {
                    if(mp[i][j] == '#') {
                        AddEdge(source, Get(i, j), di); AddEdge(Get(i, j), source, 0);
                    }else {
                        AddEdge(Get(i, j), sink, f); AddEdge(sink, Get(i, j), 0);
                    }
                }
            }
        }
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                for(int k = 0; k < 4; k++) {
                    int vx = i + dx[k], vy = j + dy[k];
                    if(vx >= 1 && vx <= h && vy >= 1 && vy <= w) {
                        int u = Get(i, j), v = Get(vx, vy);
                        AddEdge(u, v, b); AddEdge(v, u, 0);
                    }
                }
            }
        }
        printf("%d\n", cost + ISAP());
    }
    return 0;
}