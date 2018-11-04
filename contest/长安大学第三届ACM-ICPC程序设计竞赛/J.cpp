#include <bits/stdc++.h>
#define MAXN 5005
#define MAXM 100010
#define inf 0x7f7f7f7f
#define PI acos(-1.0)
using namespace std;
struct Edge{
    int to, nxt, cap;
    long double cost;
}edge[MAXM];
int head[MAXN], cnt;
int dis[MAXN], last[MAXN], vis[MAXN];
int flow;
long double cost;
inline void init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}
inline void add_edge(int u, int v, int cap, long double cost) {
    edge[cnt].to = v;edge[cnt].cap = cap;edge[cnt].cost = cost;edge[cnt].nxt = head[u];head[u] = cnt++;
}
inline void add(int u, int v, int cap, long double cost) {
    add_edge(u, v, cap, cost); add_edge(v, u, 0, -cost);
}
inline bool spfa(int s, int t) {
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
void mcmf(int s, int t) {
    flow = 0, cost = 0;
    while(spfa(s, t)) {
        int Min = inf;
        for(int i = last[t]; ~i; i = last[edge[i ^ 1].to]) Min = min(Min, edge[i].cap);
        for(int i = last[t]; ~i; i = last[edge[i ^ 1].to]) {
            cost += edge[i].cost * Min;
            edge[i].cap -= Min; edge[i ^ 1].cap += Min;
        }
        flow += Min; 
    }
}
int t, n, m, N, M;
int a[205], b[205];
double area[205], tot;
int main() {
    scanf("%d", &t);
    while(t--) {
        init(); tot = 0.0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        for(int i = 1; i <= m; ++i) scanf("%d", &b[i]);
        sort(a + 1, a + 1 + n); N = unique(a + 1, a + 1 + n) - a - 1;
        sort(b + 1, b + 1 + m); M = unique(b + 1, b + 1 + m) - b - 1;
        for(int i = 1; i <= N; ++i) area[i] = 1.0 * a[i] * a[i];   
        for(int i = 1; i <= M; ++i) area[i + N] = 1.0 * PI * b[i] * b[i];
        int RN = N + M, S = 0, T = 2 * RN + 1;
        for(int i = 1; i <= RN; ++i) {
            cout << area[i] << endl;
            add(S, i, 1, area[i]); add(i, i + RN, 1, -inf); add(i + RN, T, 1, 0);
        }
        for(int i = 1; i <= RN; ++i) {
            for(int j = 1; j <= RN; ++j) {
                if(i == j) continue;
                if(area[i] > area[j]) {
                    add(j + RN, i, 1, 0); 
                }
            }
        }
        mcmf(S, T);
        printf("%.2f\n", cost);
    }
    return 0;
}