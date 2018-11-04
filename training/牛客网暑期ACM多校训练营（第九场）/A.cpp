#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
ll inv = qpow(2, MOD-2, MOD);
void fwt_xor(ll *a, int n) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                ll x = a[i + j], y = a[i + j + d];
                a[i + j] = (x + y) % MOD;
                a[i + j + d] = (x - y + MOD) % MOD;
            }
}
void ufwt_xor(ll *a, int n) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                ll x = a[i + j], y = a[i + j + d];
                a[i + j] = (x + y) * inv % MOD;
                a[i + j + d] = ((x - y) * inv % MOD + MOD) % MOD;
            }
}
ll a[562145], b[562145], x[562145];
int n, len;
int main() {
    scanf("%d", &n);
    for(len = 1; len <= n; len<<=1);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for(int i = 0; i < n; ++i) scanf("%d", &b[i]);
    fwt_xor(b, len); fwt_xor(a, len);
    for(int i = 0; i < len; ++i) x[i] = b[i] * qpow(a[i], MOD-2, MOD) % MOD;
    ufwt_xor(x, len);
    for(int i = 0; i < n; ++i) {
        printf("%lld\n", x[i]);
    }
    return 0;
}