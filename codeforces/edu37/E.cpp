#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const int M = 2000010;
int n, m, cnt, head[N];
struct edge {
    int v, nxt;
}edge[M * 2];
struct link {
    int pre, nxt;
}L[N];
void del(int x) {
    L[L[x].pre].nxt = L[x].nxt;
    L[L[x].nxt].pre = L[x].pre;
}
void add_edge(int u, int v) {
    edge[cnt].v = v, edge[cnt].nxt = head[u], head[u] = cnt++;
}
bool vis1[N], vis2[N]; 
int scc[N], scccnt;
void bfs() {
    queue<int> q;
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    while (L[0].nxt) {  
        int now = L[0].nxt, curscc = 1;
        del(now);
        q.push(now);
        vis2[now] = 1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = head[u]; ~i; i = edge[i].nxt) vis1[edge[i].v] = 1;
            for (int i = L[0].nxt; i; i = L[i].nxt) {
                if (!vis1[i] && !vis2[i]) {
                    vis2[i] = 1;
                    q.push(i);
                    curscc++;
                    del(i);
                }
            }
            for (int i = head[u]; ~i; i = edge[i].nxt)
                vis1[edge[i].v] = 0;  
        }
        scc[++scccnt] = curscc;
    }
}
int main() {
    memset(head, -1, sizeof(head)); cnt = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v); add_edge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        L[i - 1].nxt = i;
        L[i].pre = i - 1;
    }
    L[n].nxt = 0;
    bfs();
    sort(scc + 1, scc + scccnt + 1);
    printf("%d\n", scccnt);
    for (int i = 1; i <= scccnt; i++) printf("%d%c", scc[i], i == scccnt ? '\n' : ' ');
    return 0;
}