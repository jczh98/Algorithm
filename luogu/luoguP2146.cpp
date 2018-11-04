#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int N = 300005, M = N * 2;
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
int sum[N<<2], lazy[N<<2];
inline void pushup(int rt) {
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
inline void pushdown(int rt, int l, int r) {
    if(~lazy[rt]) {
        int mid = (l+r)>>1;
        sum[rt<<1] = (mid-l+1)*lazy[rt];
        sum[rt<<1|1] = (r-mid)*lazy[rt];
        lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
        lazy[rt] = -1;
    }
}
void build(int rt, int l, int r) {
    if(l == r) {sum[rt] = 0; lazy[rt] = -1;return;}
    lazy[rt] = -1;
    int mid = (l+r)>>1;
    build(rt<<1, l, mid); build(rt<<1|1, mid+1, r);
}
void update(int rt, int l, int r, int ql, int qr, int v) {
    if(ql <= l && r <= qr) {
        lazy[rt] = v; sum[rt] = (r-l+1)*v; return;
    }
    pushdown(rt, l, r);
    int mid = (l+r)>>1;
    if(ql <= mid) update(rt<<1, l, mid, ql, qr, v);
    if(qr > mid) update(rt<<1|1, mid+1, r, ql, qr, v);
    pushup(rt);
}
void change(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        update(1, 1, n, pos[top[u]], pos[u], 1);
        u = fa[top[u]];
    }
    if(dep[u] < dep[v]) swap(u, v);
    update(1, 1, n, pos[v], pos[u], 1);
}
int v, q, ans;
char op[10];
int main() {
    init();
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        scanf("%d", &v); add(v+1, i+1); add(i+1, v+1);
    }
    dfs1(1, -1); dfs2(1, 1);
    build(1, 1, n);
    scanf("%d", &q);
    while(q--) {
        scanf("%s%d", op, &v);v++;
        ans = sum[1];
        if(op[0] == 'i') {
            change(1, v); 
            ans -= sum[1];
        }else {
            update(1, 1, n, pos[v], pos[v] + sz[v] - 1, 0);
            ans -= sum[1];
        }
        printf("%d\n", abs(ans));
    }
    return 0;
}