#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int N = 300005, M = 600010;
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
int sum[N << 2], lazy[N<<2];
inline void pushup(int x) {sum[x] = sum[x<<1] + sum[x<<1|1]; }
inline void pushdown(int rt, int l, int r) {
    if(lazy[rt]) {
        int mid = (l+r)>>1;
        sum[rt<<1] += (mid-l+1)*lazy[rt];
        sum[rt<<1|1] += (r-mid)*lazy[rt];
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        lazy[rt] = 0;
    }
}
void build(int x, int l, int r) {
    if(l == r) {
        sum[x] = 0; return;
    }
    int mid = (l + r) >> 1;
    build(x<<1, l, mid); build(x<<1|1, mid+1, r);
    pushup(x); lazy[x] = 0;
}
void update(int rt, int l, int r, int ql, int qr, int qv) {
    if(ql <= l && r <= qr) {
        sum[rt] += (r - l + 1) * qv;
        lazy[rt] += qv; return;
    }
    pushdown(rt, l, r);
    int mid = (l+r)>>1;
    if(ql <= mid) update(rt<<1, l, mid, ql, qr, qv);
    if(qr > mid) update(rt<<1|1, mid+1, r, ql, qr, qv);
    pushup(rt);
}
int query(int rt, int l, int r, int q) {
    if(l == r) return sum[rt];
    pushdown(rt, l, r);
    int mid = (l+r)>>1;
    if(q <= mid) return query(rt<<1, l, mid, q);
    else return query(rt<<1|1, mid+1, r, q);
}
inline void update(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        update(1, 1, n, pos[top[u]], pos[u], 1);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    update(1, 1, n, pos[v], pos[u], 1);
}
int u, v, rep[300005];
int main() {
    init();
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); if(i != 1) rep[a[i]]++;
    }
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs1(1, -1); dfs2(1, 1);
    build(1, 1, n);
    for(int i = 1; i < n; ++i) {
        update(a[i], a[i+1]);
    }
    for(int i = 1; i <= n; ++i) {
        cout << query(1, 1, n, pos[i]) - rep[i] << endl;
    }
    return 0;
}