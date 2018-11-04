#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int t, n, m, k, a[MAXN], b[MAXN], opt[MAXN], l_[MAXN], r_[MAXN];
int lch[MAXN << 2], rch[MAXN << 2], setv[MAXN << 2], sum[MAXN << 2];
inline void pushdown(int x, int l, int r) {
    if(setv[x]) {
        int mid = (l + r) >> 1;
        setv[x << 1] += setv[x];
        setv[x << 1 | 1] += setv[x];
        sum[x << 1] += (mid - l + 1) * setv[x];
        sum[x << 1 | 1] += (r - mid) * setv[x];
        setv[x] = 0;
    }
}
inline void pushup(int x) {
    sum[x] = sum[x << 1] + sum[x << 1 | 1];
}
void build(int x, int l, int r) {
    lch[x] = l; rch[x] = r; sum[x] = 0; setv[x] = 0;
    if(l == r) {sum[x] = 0; return;}
    int mid = (l + r) >> 1;
    build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
    pushup(x);
}
void update(int x, int l, int r, int c) {
    if(l > r) return;
    if(l <= lch[x] && rch[x] <= r) {
        sum[x] += (rch[x] - lch[x] + 1) * c;
        setv[x] += c; return;
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
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    build(1, 1, n);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &opt[i], &l_[i], &r_[i]);
        if(opt[i] == 0) {
            update(1, l_[i], r_[i], 1);
        }else update(1, l_[i], r_[i], -1);
    }
    int pos = 1;
    while(pos <= n) {
        cout << pos << endl;
        int cur = pos;
        if(query(1, pos, pos) > 0) {
            while(cur <= n && query(1, cur, cur) > 0) {
                cur++;
            }
            sort(a + 1 + pos, a + cur, greater<int>());
        }
        if(query(1, pos, pos) < 0) {
            while(cur <= n && query(1, cur, cur) < 0) {
                cur++;
            }
            sort(a + 1 + pos, a + cur, less<int>());
        }
        if(query(1, pos, pos) == 0) cur++;
        pos = cur;
    }
    cout << a[k] << endl;;
    return 0;
}