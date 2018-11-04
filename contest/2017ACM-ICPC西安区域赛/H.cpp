#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005, M = N<<2;
int t, n, m, a[N];
ll Min[M], lazy[M];
inline void pushup(int rt) {
    Min[rt] = min(Min[rt<<1], Min[rt<<1|1]);
}
inline void pushdown(int rt, int l, int r) {
    Min[rt<<1] += lazy[rt];
    Min[rt<<1|1] += lazy[rt];
    lazy[rt<<1] += lazy[rt];
    lazy[rt<<1|1] += lazy[rt];
    lazy[rt] = 0;
}
void build(int rt, int l, int r) {
    Min[rt] = INT_MAX; lazy[rt] = 0;
    if(l == r) {
        Min[rt] = a[l]; return;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid); build(rt<<1|1, mid+1, r); Min[rt] = INT_MAX;
    pushup(rt); lazy[rt] = 0;
}
void update(int rt, int l, int r, int ql, int qr, int qv) {
    if(ql <= l && r <= qr) {
        lazy[rt] += 1LL * qv; Min[rt] += 1LL * qv; return;
    }
    pushdown(rt, l, r);
    int mid = (l+r)>>1;
    if(ql <= mid) update(rt<<1, l, mid, ql, qr, qv);
    if(qr > mid) update(rt<<1|1, mid+1, r, ql, qr, qv);
    pushup(rt);
}
ll query(int rt, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return Min[rt];
    }
    pushdown(rt, l, r);
    int mid = (l+r)>>1;
    ll ret = INT_MAX;
    if(ql <= mid) ret = min(ret, query(rt<<1, l, mid, ql, qr));
    if(qr > mid) ret = min(ret, query(rt<<1|1, mid+1, r, ql, qr));
    return ret;
}
ll ans = 0;
int main() {
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        for(int i = 1; i <= n - m + 1; ++i) {
            ll ret = query(1, 1, n, i, i + m - 1);
            //cout << ret << endl;
            ans += ret;
            update(1, 1, n, i, i + m - 1, -ret);
        }
        printf("%lld\n", ans);
    }
    return 0;
}