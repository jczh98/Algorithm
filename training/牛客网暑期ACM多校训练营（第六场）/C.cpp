#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
int t;
ll fac[1000005], inv[1000005], pre[1000005], n, m;
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
ll ans, tmp;
int main() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < 1000005; i++) fac[i] = fac[i - 1] * (long long)i % MOD;
    inv[1000005 - 1] = qpow(fac[1000005 - 1], MOD - 2, MOD);
    for (int i = 1000005 - 2; i; i--) inv[i] = inv[i + 1] * (long long)(i + 1) % MOD;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d%d", &n, &m);
        ans = 0;
        if (n <= m) {
            pre[0] = 1;
            for (int i = 1; i <= n; i++)
                pre[i] = pre[i - 1] * ((m - i + 1) % MOD) % MOD;
            for (int i = 1; i <= n; i++) {
                tmp = pre[i] * fac[n - 1] % MOD * inv[i - 1] % MOD *
                      inv[n - i] % MOD;
                ans = (ans + tmp) % MOD;
            }
        } else  {
            pre[0] = 1;
            for (int i = 1; i <= m; i++)
                pre[i] = pre[i - 1] * ((n - i) % MOD) % MOD;
            for (int i = 1; i <= m; i++) {
                tmp = fac[m] * inv[m - i] % MOD * pre[i - 1] % MOD *
                      inv[i - 1] % MOD;
                ans = (ans + tmp) % MOD;
            }
        }
        printf("Case #%d: %lld\n", kase, ans);
    }
    return 0;
}
