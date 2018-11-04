#include <bits/stdc++.h>
using namespace std; 
const int N = 100005;
unsigned int X, Y, Z, W;
unsigned int RNG61() {
    X = X ^ (X<<11);
    X = X ^ (X>>4);
    X = X ^ (X<<5);
    X = X ^ (X>>14);
    W = X ^ (Y ^ Z);
    X = Y;
    Y = Z;
    Z = W;
    return Z;
}
unsigned int n, m;
long long ans;
unsigned int Min[N<<2], lazy[N<<2];
inline void pushup(unsigned int rt) {
    Min[rt] = min(Min[rt<<1], Min[rt<<1|1]);
}
inline void pushdown(unsigned int rt) {
    if(lazy[rt]!=0) {
        if(lazy[rt<<1] < lazy[rt]) {
            Min[rt<<1]=lazy[rt<<1]=lazy[rt];
        }
        if(lazy[rt<<1|1] < lazy[rt]) {
            Min[rt<<1|1]=lazy[rt<<1|1]=lazy[rt];
        }
        lazy[rt] = 0;
    }
}
void build(unsigned int rt, unsigned int l, unsigned int r) {
    Min[rt] = 0;
    if(l == r) {
        Min[rt] = 0; lazy[rt] = 0;
        return;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid); build(rt<<1|1, mid+1, r); 
    lazy[rt] = 0;
}
void update(unsigned int rt, unsigned int l, unsigned int r, unsigned int ql, unsigned int qr, unsigned int qv) {
    if(Min[rt] > qv) return;
    if(ql <= l && r <= qr) {
        if(lazy[rt] >= qv) return;
        Min[rt] = qv; lazy[rt] = qv; return;
    }
    int mid = (l+r)>>1;
    pushdown(rt);
    if(ql <= mid) update(rt<<1, l, mid, ql, qr, qv);
    if(qr > mid) update(rt<<1|1, mid+1, r, ql, qr, qv);
    pushup(rt);
}
unsigned int query(unsigned int rt, unsigned int l, unsigned int r, unsigned int q) {
    if(l == r) return Min[rt];
    pushdown(rt);
    unsigned int mid = (l+r)>>1;
    if(q <= mid) return query(rt<<1, l, mid, q);
    else return query(rt<<1|1, mid+1, r, q);
}
unsigned f1, f2, f3, l, r, v;
int main() {
    //freopen("out.txt", "w", stdout);
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        ans = 0;
        cin >> n >> m >> X >> Y >> Z;
        build(1, 1, n);
        for(int i = 1; i <= m; ++i) {
            f1 = RNG61(); f2 = RNG61(); f3 = RNG61();
            l = min(f1 % n + 1, f2 % n + 1);
            r = max(f1 % n + 1, f2 % n + 1);
            v = f3 % 1073741824;
            update(1, 1, n, l, r, v);
            //cout << l << " " << r << " " << v << endl;
        }
        for(long long i = 1; i <= n; ++i) {
            ans = ans ^ (i * query(1, 1, n, i));
            //cout << query(1, 1, n, i) << " ";
        }
        //cout << endl;
        cout << ans << endl;
    }
    return 0;
}