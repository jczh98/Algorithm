#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long LL;
const LL inf = 1e18 + 1;
LL t, n, u, v, ans, vis[MAXN];
LL k, a[MAXN], H[2 * MAXN], C[2 * MAXN], tot;
struct Edge{
    int to, nxt;
}edge[2 * MAXN];
LL head[MAXN], cnt;
void Init() {
    memset(vis, 0, sizeof(vis));
    memset(C, 0, sizeof(C));
    ans = 0;
    tot = 0;
    cnt = 0;
    memset(head, -1, sizeof(head));
}
inline void AddEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].nxt = head[u];
    head[u] = cnt++;
}
inline void Modify(int x, int v) {
    while(x <= tot) {
        C[x] += v;
        x += (x & (-x));
    }
}
inline int Sum(int x) {
    int res = 0;
    while(x > 0) {
        res += C[x];
        x -= (x & (-x));
    }
    return res;
}
int DFS(int u) {
    int p = lower_bound(H, H + tot, a[u] ? k / a[u] : inf) - H + 1, q = lower_bound(H, H + tot, a[u]) - H + 1;
    ans += Sum(p);
    Modify(q, 1);
    for(int i = head[u]; ~i; i = edge[i].nxt) {
        DFS(edge[i].to);
    }
    Modify(q, -1);
}
int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%I64d%I64d", &n, &k);
        Init();
        for(int i = 1; i <= n; i++) {
            scanf("%I64d", &a[i]);
            H[tot++] = a[i];
            if(a[i] == 0) {
                H[tot++] = inf;
            }else {
                H[tot++] = k / a[i];
            }
        }
        sort(H, H + tot);
        tot = unique(H, H + tot) - H;
        for(int i = 1; i < n; i++) {
            scanf("%I64d%I64d", &u, &v);
            vis[v] = 1;
            AddEdge(u, v);
        }
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                DFS(i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

