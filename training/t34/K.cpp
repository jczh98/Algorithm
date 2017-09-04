#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;
typedef long long LL;
struct Edge{
    int u, v, c;
    bool operator < (const Edge & rhs) const {
        return c < rhs.c;
    }
}edge[MAXN];
int fa[MAXN];
int Find(int x) {
    return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]);
}
int n, m;
LL a[MAXN], b[MAXN], d[MAXN], ans = 0;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
        d[i] = a[i] * b[i];
        fa[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].c);
    }
    sort(edge + 1, edge + 1 + m);
    for(int i = 1; i <= m; i++) {
        int x = Find(edge[i].u), y = Find(edge[i].v);
        if(x == y) continue;
        fa[x] = y;
        d[y] = min(d[x] + d[y], max((LL) edge[i].c, max(a[x], a[y])) * min(b[x], b[y]));
        a[y] = max((LL) edge[i].c, max(a[x], a[y]));
        b[y] = min(b[x], b[y]);
    }
    for(int i = 1; i <= n; i++) {
        if(Find(i) == i) {
            ans += d[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}

