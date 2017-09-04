#include <bits/stdc++.h>
#define MAXN 5005
#define MAXM 100010
#define inf 0x7f7f7f7f
using namespace std;
struct Edge{
    int to, nxt, cap, cost;
}edge[MAXM];
int head[MAXN], cnt;
int d[MAXN], last[MAXN], vis[MAXN];
int flow, cost;
void Init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void AddEdge(int u, int v, int cap, int cost) {
    edge[cnt].to = v;
    edge[cnt].cap = cap;
    edge[cnt].cost = cost;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
bool Spfa(int s, int t, int &flow, int &cost) {
    memset(last, -1, sizeof(last));
    memset(d, 127, sizeof(d));
    memset(vis, 0,sizeof(vis));
    d[s] = 0; vis[s] = 1; last[s] = -1;
    queue<int> que; que.push(s);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        vis[u] = 0;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(edge[i].cap && d[v] > d[u] + edge[i].cost) {
                d[v] = d[u] + edge[i].cost;
                last[v] = i;
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    if(d[t] == inf) return false;
    int mi = inf;
    for(int i = last[t]; ~i; i = last[edge[i ^ 1].to]) mi = min(mi, edge[i].cap);
    flow += mi;
    for(int i = last[t]; ~i; i = last[edge[i ^ 1].to]) {
        cost += edge[i].cost * mi;
        edge[i].cap -= mi;
        edge[i ^ 1].cap += mi;
    }
    return true;
}
void MCMF(int s, int t) {
    flow = 0, cost = 0;
    while(Spfa(s, t, flow, cost));
}

int n, m, s, t, u, v, f, c;
int main() {
    Init();
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d%d", &u, &v, &f, &c);
        AddEdge(u, v, f, c);
        AddEdge(v, u, 0, -c);
    }
    MCMF(s, t);
    printf("%d %d\n", flow, cost);
    return 0;
}

