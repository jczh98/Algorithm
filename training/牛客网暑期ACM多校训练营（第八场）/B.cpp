#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 362150;
const ll MOD = 998244353;
ll finv[N], fac[N], inv[N];
void precalc() {
    fac[0] = 1; 
    for(int i = 1; i < N; ++i) {
        fac[i] = 1LL*fac[i - 1] * i % MOD;
    }
    inv[1] = 1;
    for(int i = 2; i < N; ++i) {
        inv[i] = (ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    finv[0] = 1;
    for(int i = 1; i < N; ++i) {
        finv[i] = 1LL*finv[i-1]*inv[i]%MOD;
    }
}
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
ll C(ll n, ll m) {
    if(m < 0) return 0;
    return fac[n] * finv[m] % MOD * finv[n-m] % MOD;
}
ll n, ans = 0;
int main() {
    precalc();
    cin >> n; 
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    n = n - 1;
    for(int i = 1; i <= n; ++i) {
        ans = (ans + C(n, i) * C(n, i - 1) % MOD * qpow(2, i, MOD) % MOD) % MOD;
    }
    ans = ans * qpow(n, MOD-2, MOD) % MOD;
    cout << ans << endl;
    return 0;
}