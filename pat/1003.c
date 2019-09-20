#include <stdio.h>
#include <string.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define N 555
#define M 800010
int n, m, c1, c2, u, v, len, num[600];
int head[N], nxt[M], val[M], to[M], cnt;
int dis[N], vis[N], ans[N];
int queue[4*N], front, end;
void init() {
    memset(head, -1, sizeof(head));
    cnt=0;
}
void addedge(int u, int v, int w) {
    to[cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}
int main() {
    init();
    scanf("%d%d%d%d",&n, &m, &c1, &c2);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &num[i-1]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &len);
        addedge(u, v, len);
        addedge(v, u, len);
    }
    memset(vis, 0, sizeof(vis));
    memset(dis, 127, sizeof(vis));
    memset(queue, 0, sizeof(queue));
    front = 0; end = 0;
    queue[end++] = c1;
    vis[c1] = 1; dis[c1] = 0; ans[c1] = num[c1];
    while(front < end) {
        int u = queue[front++];
        if (u == c2) continue;
        for (int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i];
            if (dis[v] > dis[u] + val[i]) {
                dis[v] = dis[u] + val[i];
                ans[v] = ans[u] + num[v];
                if (!vis[v]) {
                    queue[end++]=v;
                }
                vis[v] = vis[u];
            } else if (dis[v] == dis[u] + val[i]) {
                ans[v] = max(ans[u] + num[v], ans[v]);
                if (!vis[v]) {
                    queue[end++]=v;
                }
                vis[v] += vis[u];
            }
        }
        vis[u] = 0;
    }
    printf("%d %d\n", vis[c2], ans[c2]);
}
