#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int N = 100005, M = 200005;
int l, r, d, n, m, x[N];
int counter = 1;
int head[N], nxt[M * 2], to[M * 2], val[M * 2], cnt, dis[N], vis[N]; 
void add(int u, int v, int w) {
    to[cnt] = v;
    val[cnt] = w;
    nxt[cnt] = head[u];
    head[u] = cnt++;
}
bool spfa(int u) {
    queue<int> que;
    que.push(u); dis[u] = 0; vis[u] = 1;
    while(!que.empty()) {
        int now = que.front(); que.pop();
        for(int i = head[now]; ~i; i = nxt[i]) {
            int v = to[i];
            if(!vis[v]) {
                dis[v] = dis[now] + val[i];
                que.push(v); vis[v] = 1;    
            }else if(dis[v] != dis[now] + val[i]) {
                return false;
            }                      
        }
    }
    return true;
}
int main() {
    memset(head, -1, sizeof(head));
    memset(dis, 127, sizeof(dis));
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &l, &r, &d);
        add(l, r, d); add(r, l, -d);
    }
    int flag = 0;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            if(!spfa(i)) flag = 1;
        }
    }
    if(flag) printf("No\n"); else printf("Yes\n");
    return 0;
}