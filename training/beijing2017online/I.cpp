#include <bits/stdc++.h>
using namespace std;
#define INF (LONG_LONG_MAX - 100)
#define ll long long
const ll maxn = 2e5 + 7;
struct nd {
    ll l, r, maxv, minv, lz;
} seg[maxn << 2];
ll n;
inline void pushup(ll rt) {
    seg[rt].maxv = max(seg[rt << 1].maxv, seg[rt << 1 | 1].maxv);
    seg[rt].minv = min(seg[rt << 1].minv, seg[rt << 1 | 1].minv);
}
void pushdown(ll rt) {
    if(seg[rt].lz) {
        seg[rt << 1].lz = seg[rt].lz;
        seg[rt << 1 | 1].lz = seg[rt].lz;
        seg[rt << 1].maxv = seg[rt].lz;
        seg[rt << 1 | 1].maxv = seg[rt].lz;
        seg[rt << 1].minv = seg[rt].lz;
        seg[rt << 1 | 1].minv = seg[rt].lz;
        seg[rt].lz = 0;
    }
}
void bulid(ll b = 1, ll e = n, ll rt = 1) {
    seg[rt].l = b;
    seg[rt].r = e;
    if(b == e) {
        seg[rt].maxv = -INF;
        seg[rt].minv = INF;
        return ;
    }
    ll m = b + e >> 1;
    bulid(b, m, rt << 1);
    bulid(m + 1, e, rt << 1 | 1);
    pushup(rt);
}
void update(ll l, ll r, ll xx, ll b = 1, ll e = n, ll rt = 1) {
    if(l <= b && e <= r) {
        seg[rt].lz = xx;
        seg[rt].maxv = xx;
        seg[rt].minv = xx;
        return ;
    }
    pushdown(rt);
    ll m = b + e >> 1;
    if(l <= m)
        update(l, r, xx, b, m, rt << 1);
    if(r > m)
        update(l, r, xx, m + 1, e, rt << 1 | 1);
    pushup(rt);
}
ll queryMax(ll l, ll r, ll b = 1, ll e = n, ll rt = 1) {
    if(l <= b && e <= r) {
        return seg[rt].maxv;
    }
    pushdown(rt);
    ll m = b + e >> 1;
    ll re = -INF;
    if(l <= m)
        re = max(re, queryMax(l, r, b, m, rt << 1));
    if(r > m)
        re = max(re, queryMax(l, r, m + 1, e, rt << 1 | 1));
    return re;
}
ll queryMin(ll l, ll r, ll b = 1, ll e = n, ll rt = 1) {
    if(l <= b && e <= r) {
        return seg[rt].minv;
    }
    pushdown(rt);
    ll m = b + e >> 1;
    ll re = INF;
    if(l <= m)
        re = min(re, queryMin(l, r, b, m, rt << 1));
    if(r > m)
        re = min(re, queryMin(l, r, m + 1, e, rt << 1 | 1));
    return re;
}
ll a[maxn], t, k, q, type, l, r, ans, maxv, minv;
int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &k);
        n = pow(2, k) - 1;
        bulid(0, n, 1);
        for(ll i = 0; i <= n; ++i) {
            scanf("%lld", &a[i]);
            update(i, i, a[i], 0, n, 1);
        }
        scanf("%lld", &q);
        for(ll i = 0; i < q; ++i) {
            scanf("%lld%lld%lld", &type, &l, &r);
            if(type == 1) {
                maxv = queryMax(l, r, 0, n, 1);
                minv = queryMin(l, r, 0, n, 1);
                //cout << maxv << " " << minv << endl;
                ans = min(min(minv * minv, maxv * minv), maxv * maxv);
                printf("%lld\n", ans);
            }else {
                update(l, l, r, 0, n, 1);
            }
        }
    }
    return 0;
}