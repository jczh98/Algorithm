#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int t, n, m, k, a[MAXN], b[MAXN], opt[MAXN], l_[MAXN], r_[MAXN];
int lch[MAXN << 2], rch[MAXN << 2], setv[MAXN << 2], sum[MAXN << 2];
inline void pushdown(int x, int l, int r) {
    if(~setv[x]) {
        int mid = (l + r) >> 1;
        setv[x << 1] = setv[x << 1 | 1] = setv[x];
        sum[x << 1] = (mid - l + 1) * setv[x];
        sum[x << 1 | 1] = (r - mid) * setv[x];
        setv[x] = -1;
    }
}
inline void pushup(int x) {
    sum[x] = sum[x << 1] + sum[x << 1 | 1];
}
void build(int x, int l, int r) {
    lch[x] = l; rch[x] = r; sum[x] = 0; setv[x] = -1;
    if(l == r) {sum[x] = b[l]; return;}
    int mid = (l + r) >> 1;
    build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
    pushup(x);
}
void update(int x, int l, int r, int c) {
    if(l > r) return;
    if(l <= lch[x] && rch[x] <= r) {
        sum[x] = (rch[x] - lch[x] + 1) * c;
        setv[x] = c; return;
    }
    pushdown(x, lch[x], rch[x]);
    int mid = (lch[x] + rch[x]) >> 1;
    if(r <= mid) update(x << 1, l, r, c);
    else if(l > mid) update(x << 1 | 1, l, r, c);
    else update(x << 1, l, mid, c), update(x << 1 | 1, mid + 1, r, c);
    pushup(x);
}
int query(int x, int l, int r) {
    if(l <= lch[x] && rch[x] <= r) {
        return sum[x];
    }
    pushdown(x, lch[x], rch[x]);
    int mid = (lch[x] + rch[x]) >> 1, ans = 0;
    if(r <= mid) return query(x << 1, l, r);
    else if(l > mid) return query(x << 1 | 1, l, r);
    else return query(x << 1, l, mid) + query(x << 1 | 1, mid + 1, r);
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d%d", &opt[i], &l_[i], &r_[i]);
        }
        scanf("%d", &k);
        int L = 1, R = n, ans = 0;
        while(L <= R) {
            int mid = (L + R) >> 1;
            //cout << mid << endl;
            memset(b, 0, sizeof(b));
            for(int i = 1; i <= n; ++i) b[i] = (a[i] >= mid ? 1 : 0);
            build(1, 1, n);
            // for(int i = 1; i <= n; ++i) {
            //     cout << query(1, i, i) << " ";
            // }cout << endl;
            for(int i = 1; i <= m; ++i) {
                int sum = query(1, l_[i], r_[i]);
                //cout << sum << endl;
                if(opt[i] == 0) {
                    update(1, l_[i], r_[i] - sum, 0);
                    update(1, r_[i] - sum + 1, r_[i], 1);
                }else {
                    update(1, l_[i], l_[i] + sum - 1, 1);
                    update(1, l_[i] + sum, r_[i], 0);
                }
                // for(int i = 1; i <= n; ++i) {
                //     cout << query(1, i, i) << " ";
                // }cout << endl;
            }
            // for(int i = 1; i <= n; ++i) {
            //     cout << query(1, i, i) << " ";
            // }cout << endl;
            if(query(1, k, k)) {
                L = mid + 1; ans = mid;
            }else R = mid - 1;
        }
        cout << ans << endl;;
    }
    return 0;
}