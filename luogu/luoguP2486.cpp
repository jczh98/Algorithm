#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int N = 200005, M = 200010;
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
int num[N << 2], rr[N << 2], ll[N << 2], lazy[N << 2];
inline void pushup(int x) {
    num[x] = num[x<<1] + num[x<<1|1];
    rr[x] = rr[x<<1|1]; ll[x] = ll[x<<1];
    if(rr[x<<1] == ll[x<<1|1]) num[x]--;
}
inline void pushdown(int x) {
    if(lazy[x]) {
        lazy[x<<1] = lazy[x<<1|1] = lazy[x];
        num[x<<1] = num[x<<1|1] = 1;
        ll[x<<1] = rr[x<<1] = lazy[x];
        ll[x<<1|1] = rr[x<<1|1] = lazy[x];
        lazy[x] = 0;
    }
}
void build(int x, int l, int r) {
    if(l == r) {
        num[x] = 1; ll[x] = rr[x] = a[pre[l]]; return;
    }
    int mid = (l+r)>>1;
    build(x<<1, l, mid); build(x<<1|1, mid+1, r);
    pushup(x);
}
void update(int x, int l, int r, int ql, int qr, int v) {
    if(ql <= l && r <= qr) {
        lazy[x] = v; ll[x] = rr[x] = v; num[x] = 1; return;
    }
    pushdown(x);
    int mid = (l+r)>>1;
    if(ql <= mid) update(x<<1, l, mid, ql, qr, v);
    if(qr > mid) update(x<<1|1, mid+1, r, ql, qr, v);
    pushup(x);
}
int query(int x, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return num[x];
    }
    pushdown(x); 
    int mid = (l+r)>>1, ans = 0;
    if(ql <= mid) ans += query(x<<1, l, mid, ql, qr);
    if(qr > mid) ans += query(x<<1|1, mid+1, r, ql, qr);
    if(ql <= mid && qr > mid && rr[x<<1] == ll[x<<1|1]) ans--;
    return ans;
}
int query(int x, int l, int r, int q) {
    if(l == r) return ll[x];
    pushdown(x);
    int mid = (l+r)>>1;
    if(q <= mid) return query(x<<1, l, mid, q);
    else return query(x<<1|1, mid+1, r, q);
}
inline void change_path(int u, int v, int val) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        update(1, 1, n, pos[top[u]], pos[u], val);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    update(1, 1, n, pos[v], pos[u], val);
}
inline int query_path(int u, int v) {
    int ans = 0;
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        ans += query(1, 1, n, pos[top[u]], pos[u]);
        if(query(1, 1, n, pos[top[u]]) == query(1, 1, n, pos[fa[top[u]]])) ans--;
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    ans += query(1, 1, n, pos[v], pos[u]);
    return ans;
}
int m, u, v, w;
char op[10];
int main() {
    init();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for(int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs1(1, -1); dfs2(1, 1);
    build(1, 1, n);
    scanf("%d", &m);
    while(m--) {
        scanf("%s", op);
        if(op[0] == 'C') {
            scanf("%d%d%d", &u, &v, &w);
            change_path(u, v, w);
        }else {
            scanf("%d%d", &u, &v);
            printf("%d\n", query_path(u, v));
        }
    }
    return 0;
}