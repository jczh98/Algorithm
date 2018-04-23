#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
LL qpow(LL a, LL b, LL mod) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
LL fac[100005], inv[100005];
int t;
LL n, a, b, m;
int main() {
    fac[0] = 1;
    for(LL i = 1; i <= 100000; ++i) fac[i] = fac[i - 1] * i % MOD;
    inv[100000] = qpow(fac[100000], MOD - 2, MOD);
    for(LL i = 100000 - 1; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % MOD;
    cin >> t;
    while(t--) {
        cin >> a >> b >> n >> m;
        LL ans = fac[n - 1] * inv[m - 1] % MOD * inv[n - m] % MOD * qpow(a, n - m, MOD) % MOD * qpow(b, m - 1, MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}