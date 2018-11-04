#include <bits/stdc++.h>
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
using namespace std;
const int N = 200005;
int n, t[N], x[N], y[N], v[3 * N], cnt;
set<int> st[(3 * N)<<2];
void build(int rt, int l, int r) {
    if(l == r) {
        st[rt].clear();
        return ;
    }
    int mid = (l + r) >> 1;
    build(ls(rt), l, mid); build(rs(rt), mid + 1, r);
}
void update(int rt, int l, int r, int ql, int qr, int v, int flag) {
    if(ql <= l && r <= qr) {
        if(flag) {
            st[rt].insert(v);
        }else {
            st[rt].erase(v);
        }
        return;
    }
    int mid = (l + r) >> 1;
    if(ql <= mid) update(ls(rt), l, mid, ql, qr, v, flag);
    if(qr > mid) update(rs(rt), mid + 1, r, ql, qr, v, flag);
}
int query(int rt, int l, int r, int v, int p) {
    if(l <= v && v <= r) {
        for(set<int>::iterator it = st[rt].begin(); it != st[rt].end(); it++) {
            int id = *it;
            if(1LL * (x[p] - x[id]) * (x[p] - x[id]) + 1LL * (y[p] - y[id]) * (y[p] - y[id]) < 1LL * y[id] * y[id]) {
                return id;
            }
        }
    }
    if(l == r) return -1;
    int mid = (l + r) >> 1;
    if(v <= mid) return query(ls(rt), l, mid, v, p); 
    else return query(rs(rt), mid + 1, r, v, p);
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d%d", &t[i], &x[i], &y[i]);
        if(t[i] == 1) {
            v[++cnt] = x[i] + y[i]; v[++cnt] = x[i] - y[i];
        }else {
            v[++cnt] = x[i];
        }
    }
    sort(v + 1, v + 1 + cnt);
    int m = unique(v + 1, v + 1 + cnt) - v;
    build(1, 1, m);
    for(int i = 1; i <= n; ++i) {
        if(t[i] == 1) {
            int l = lower_bound(v + 1, v + 1 + m, x[i] - y[i]) - v;
            int r = upper_bound(v + 1, v + 1 + m, x[i] + y[i]) - v;
            update(1, 1, m, l, r, i, 1);
        } else {
            int xx = lower_bound(v + 1, v + 1 + m, x[i]) - v;
            int ret = query(1, 1, m, xx, i);
            if(ret != -1) {
                int l = lower_bound(v + 1, v + 1 + m, x[ret] - y[ret]) - v;
                int r = upper_bound(v + 1, v + 1 + m, x[ret] + y[ret]) - v;
                update(1, 1, m, l, r, ret, 0);
            }
            printf("%d\n", ret);
        }
    }
    return 0;
}