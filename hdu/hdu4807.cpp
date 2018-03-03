#include <bits/stdc++.h>
#define MAXN 5005
#define MAXM 100010
#define inf 0x7f7f7f7f
using namespace std;
struct Edge{
    int to, nxt, cap, cost;
}edge[MAXM];
int head[MAXN], cnt;
int dis[MAXN], last[MAXN], vis[MAXN];
int flow, cost, ans;
void init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
void add_edge(int u, int v, int cap, int cost) {
    edge[cnt].to = v;
    edge[cnt].cap = cap;
    edge[cnt].cost = cost;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
bool spfa(int s, int t) {
    memset(last, -1, sizeof(last));
    memset(dis, 127, sizeof(dis));
    memset(vis, 0,sizeof(vis));
    dis[s] = 0; vis[s] = 1; last[s] = -1;
    queue<int> que; que.push(s);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        vis[u] = 0;
        for(int i = head[u]; ~i; i = edge[i].nxt) {
            int v = edge[i].to;
            if(edge[i].cap && dis[v] > dis[u] + edge[i].cost) {
                dis[v] = dis[u] + edge[i].cost;
                last[v] = i;
                if(!vis[v]) {
                    que.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return last[t] != -1;
}
void mcmf(int s, int t, int k) {
    flow = 0, cost = 0; ans = inf;
    int last_time, tot = k;
    while(spfa(s, t)) {
        int Min = inf;
        for(int i = last[t]; ~i; i = last[edge[i ^ 1].to]) Min = min(Min, edge[i].cap);
        for(int i = last[t]; ~i; i = last[edge[i ^ 1].to]) {
            cost += edge[i].cost * Min;
            edge[i].cap -= Min; edge[i ^ 1].cap += Min;
        }
        tot -= flow * (dis[t] - last_time) + Min; 
        flow += Min; last_time = dis[t]; tot = max(tot, 0);
        ans = min(ans, dis[t] + (int)ceil(1.0 * tot / flow));
        if(tot < 1) break;
    }
}
int n, m, k, a, b, c;
int main() {
    while(scanf("%d%d%d", &n, &m, &k) != EOF) {
        init();
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &a, &b, &c); a++; b++;
            add_edge(a, b, c, 1); add_edge(b, a, 0, -1);
        }
        if(k == 0) {printf("0\n"); continue;}
        mcmf(1, n, k);
        if(ans == inf) printf("No solution\n"); else printf("%d\n", ans);
    }
    return 0;
}