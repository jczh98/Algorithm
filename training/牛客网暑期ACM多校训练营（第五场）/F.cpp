#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> par;
const int N = 100005, MOD = 998244353;
int n, p[N], d[N];
par D[N];
ll mul[N<<2];
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
} 
inline void pushup(int rt) {
    mul[rt] = mul[rt<<1] * mul[rt<<1|1] % MOD;;
}
void build(int rt, int l, int r) {
    mul[rt] = 1;
    if(l == r) {
        mul[rt] = 1; return;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid); build(rt<<1|1, mid+1, r);
}
void update(int rt, int l, int r, int q, ll v) {
    if(l == r) {
        mul[rt] = v; return;
    }
    int mid = (l+r)>>1;
    if(q <= mid) update(rt<<1, l, mid, q, v);
    if(q > mid) update(rt<<1|1, mid+1, r, q, v);
    pushup(rt);
}
ll query(int rt, int l, int r, int ql, int qr) {
    if(ql > qr) return 1;
    if(ql <= l && r <= qr) {
        return mul[rt];
    }
    int mid = (l+r)>>1;
    ll ans = 1;
    if(ql <= mid) ans = (ans * query(rt<<1, l, mid, ql, qr)) % MOD;
    if(qr > mid) ans = (ans * query(rt<<1|1, mid+1, r, ql, qr)) % MOD;
    return ans;
}
int main() {
    ll inv = qpow(100, MOD - 2, MOD);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &p[i], &D[i].first); D[i].second = i;
    }
    sort(D+1, D+n+1);
    build(1, 1, n);
    ll ans = 0;
    for(int i = n; i >= 1; --i) {
        ll t = query(1, 1, n, 1, D[i].second - 1);  
        ans = (ans + t * p[D[i].second] % MOD * inv % MOD) % MOD;
        update(1, 1, n, D[i].second, inv * (100 - p[D[i].second]) % MOD);
    }
    cout << ans << endl;
    return 0;
}