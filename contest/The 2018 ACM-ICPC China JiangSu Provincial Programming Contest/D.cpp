#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, N = 2000000;
ll finv[N+5], fac[N+5], inv[N+5];
void precalc() {
    fac[0] = 1;
    for(int i = 1; i <= N; ++i) {
        fac[i] = 1LL * fac[i-1]*i%mod;
    }
    inv[1] = 1;
    for(int i = 2; i <= N; ++i) {
        inv[i] = 1LL*(mod-mod/i)*inv[mod%i]%mod;
    }
    finv[0] = 1;
    for(int i = 1; i <= N; ++i) {
        finv[i] = 1LL*finv[i-1]*inv[i]%mod;
    }
}
inline ll C(ll n, ll m) {
    return fac[n]*finv[m]%mod*finv[n-m]%mod;
}
int main() {
    precalc();
    int i, j, n, m, t;
    while (scanf("%d", &n) != EOF) {
        ll ans = 1;
        ll kong = 1;
        for (i = 0; i < n; i++) {
            ll x;
            scanf("%lld", &x);
            ans = ans * C(x + kong - 1, kong - 1) % mod;
            kong += x;
        }
        cout << ans << endl;
    }
    return 0;
}