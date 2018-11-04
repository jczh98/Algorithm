#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005, MOD = 998244353;
int t;
int val[N<<2], lazy[N<<2];
inline void pushdown(int rt) {
    if(~lazy[rt]) {
        lazy[rt<<1]=lazy[rt<<1|1]=val[rt<<1]=val[rt<<1|1]=lazy[rt];
        lazy[rt]=0;
    }
}
void update(int rt, int l, int r, int ql, int qr, int v) {
    if(ql <= l && r <= qr) {
        lazy[rt] = val[rt] = v; return;
    }
    pushdown(rt);
    int mid = (l + r)>>1;
    if(ql <= mid) update(rt<<1, l, mid, ql, qr, v);
    if(qr > mid) update(rt<<1|1, mid+1, r, ql, qr, v);
}
int query(int rt, int l, int r, int q) {
    if(l == r && l == q) {
        return val[rt];
    }
    int mid = (l+r)>>1, ans = 0;
    if(q <= mid) ans += query(rt<<1, l, mid, q);
    if(q > mid) ans += query(rt<<1|1, mid+1, r, q);
    return ans;
}
int n, m, l[N], r[N], pos[N], cnt = 0, x, y, last;
vector<pair<int,int>> vec;
int main() {
    scanf("%d", &t);
    while(t--) {
        last = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            scanf("%d%d", &l[i], &r[i]);
            pos[cnt++]=l[i]; pos[cnt++]=r[i];
            vec.push_back(make_pair(l[i], r[i]));
        }
        sort(pos,pos+cnt);
        int m = unique(pos, pos+cnt) - pos;
        for(int i = 1; i <= m; ++i) {
            scanf("%d", &y);
            x = (y ^ (last%MOD));
            int q = lower_bound(pos, pos+m, x) - pos;
        }
    }
}