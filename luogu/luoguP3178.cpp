#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long ll;
const int N = 100005, M = 300005;
int head[N], nxt[M], to[M], cnt;
int sz[N], dep[N], fa[N], top[N], wson[N], pre[M], pos[N], ind = 0;
int a[N], n;
inline void init() {memset(head, -1, sizeof(head)); cnt = 0; dep[1] = 1; fa[1] = 1;}
inline void add(int u, int v) {to[cnt] = v; nxt[cnt] = head[u]; head[u] = cnt++;}
void dfs1(int u, int f) {
    sz[u] = 1;
    for(int i = head[u]; ~i; i = nxt[i]) {        
        int v = to[i]; if(f == v) continue;
        dep[v] = dep[u] + 1; fa[v] = u; dfs1(v, u);
        sz[u] += sz[v]; if(sz[v] > sz[wson[u]]) wson[u] = v;
    }
}
void dfs2(int u, int h) {
    top[u] = h; pos[u] = ++ind;  pre[ind] = u;
    if(wson[u]) dfs2(wson[u], h);
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = to[i]; if(v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}
ll sum[N<<2], lazy[N<<2];
inline void pushup(int rt) {sum[rt] = sum[rt<<1] + sum[rt<<1|1];}
inline void pushdown(int rt, int l, int r) {
    if(lazy[rt]) {
        int mid = (l+r)>>1;
        sum[rt<<1] += lazy[rt]*(mid-l+1);
        sum[rt<<1|1] += lazy[rt]*(r-mid);
        lazy[rt<<1] += lazy[rt]; lazy[rt<<1|1] += lazy[rt];
        lazy[rt] = 0;
    }
}
void build(int rt, int l, int r) {
    if(l == r) {
        sum[rt] = a[pre[l]];
        return;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid); build(rt<<1|1, mid+1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int ql, int qr, int v) {
    if(ql <= l && r <= qr) {
        sum[rt] += 1LL * v * (r-l+1); lazy[rt] += 1LL * v; return;
    }
    pushdown(rt, l, r);
    int mid = (l+r)>>1;
    if(ql <= mid) update(rt<<1, l, mid, ql, qr, v);
    if(qr > mid) update(rt<<1|1, mid+1, r, ql, qr, v);
    pushup(rt);
}
ll query(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) return sum[rt];
    pushdown(rt, l, r);
    int mid = (l+r)>>1; ll ans = 0;
    if(ql <= mid) ans += query(rt<<1, l, mid, ql, qr);
    if(qr > mid) ans += query(rt<<1|1, mid+1, r, ql, qr);
    return ans;
}
inline ll ask(int u, int v) {
    ll ans = 0;
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        ans += query(1, 1, n, pos[top[u]], pos[u]);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    ans += query(1, 1, n, pos[v], pos[u]);
    return ans;
}
int m, x, y, z;
int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs1(1, -1); dfs2(1, 1);
    build(1, 1, n);
    for(int i = 1; i <= m; ++i) {
        scanf("%d", &x);
        if(x == 1) {
            scanf("%d%d", &y, &z);
            update(1, 1, n, pos[y], pos[y], z);
        }else if(x == 2){
            scanf("%d%d", &y, &z);
            update(1, 1, n, pos[y], pos[y]+sz[y]-1, z);
        }else if(x == 3) {
            scanf("%d", &y);
            cout << ask(1, y) << endl;
        }
    }
    return 0;
}