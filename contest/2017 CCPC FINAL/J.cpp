#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int N = 2005, M = 20005;
int head[N], nxt[M], val[M], to[M], cnt;
int dis[N], Out[N];
bool vis[N];
inline void init() {memset(head, -1, sizeof(head)); cnt=0;}
inline void addedge(int u, int v, int w) {
    to[cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}
bool spfa(int s, int n) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 127, sizeof(dis));
    memset(Out, 0, sizeof(Out));
    dis[s] = 0; vis[s] = 1; Out[s] = 1;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        vis[u] = 0; 
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[u] + val[i]) {
                dis[v] = dis[u] + val[i];
                if(!vis[v]) {
                    vis[v] = 1; que.push(v);
                    if(++Out[v] > n) return false;
                }
            }
        }
    }
    return true;
}
int t, n, m, x, a, b, c, d;
int main() {
    scanf("%d", &t);
    for(int kase = 1; kase <= t; ++kase) {
        init();
        scanf("%d%d%d", &n, &m, &x);
        for(int i = 1; i < n; ++i) {
            addedge(i, i+1, -1);
        }
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if(a == b && c == d) {
                addedge(c, a, x); addedge(a, c, -x);
            }else {
                addedge(a, d, -(x+1)); addedge(c, b, x-1);
            }
        }
        printf("Case #%d: ", kase);
        if(!spfa(1, n)) {
            printf("IMPOSSIBLE\n");
        }else {
            for(int i = 1; i < n; ++i) {
                printf("%d%c", dis[i]-dis[i+1], i == n-1?'\n':' ');
            }
        }
    }
    return 0;
}