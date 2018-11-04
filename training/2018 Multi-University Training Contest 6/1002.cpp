#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000005, MOD = 1e9+7;
bool check[N];
int prime[N], mu[N], tot;
void mobius() {
    memset(check, 0, sizeof(check));
    mu[1] = 1; tot = 0;
    for(int i = 2; i < N; ++i) {
        if(!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; ++j) {
            if(i * prime[j] > N) break;
            check[i * prime[j]] = true;
            if(i % prime[j] == 0) {
                mu[i * prime[j]] = 0; break;
            }else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}
inline ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
int finv[2*N], fac[2*N], inv[2*N], fib[N];
inline void precalc() {
    fac[0] = 1; 
    for(int i = 1; i < 2*N; ++i) {
        fac[i] = 1LL*fac[i - 1] * i % MOD;
    }
    inv[1] = 1;
    for(int i = 2; i < 2*N; ++i) {
        inv[i] = (ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    finv[0] = 1;
    for(int i = 1; i < 2*N; ++i) {
        finv[i] = 1LL*finv[i-1]*inv[i]%MOD;
    }
    fib[0] = 1; fib[1] = 2;
    for(int i = 2; i < N; ++i) {
        //fib[i] = (fib[i-1]+fib[i-2])%(MOD-1);
        fib[i] = 1LL*fib[i-1]*fib[i-2]%MOD;
    }
}
inline ll C(ll n, ll m) {
    return 1LL*fac[n]*finv[m]%MOD*finv[n-m]%MOD;
}
int t, n, k;
ll f[N];
int main() {
    precalc();
    mobius();
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) {
            if(n%i ==0 ) f[i] = C(n/i+k-1,n/i);
            else f[i] = 0;
        }
        ll ans = 0;
        for(int i = 1; i <= n; ++i) {
            ll gi = 0;
            for(int j = i; j <= n; j += i) {
                gi = (gi + 1LL*mu[j/i]*f[j] + MOD)%MOD;
            }
            ans = (ans + (1LL*fib[i]-1LL+MOD)%MOD*gi%MOD)%MOD;
        }
        ans = ans*qpow(C(n+k-1,n),MOD-2,MOD)%MOD;
        printf("%lld\n", ans);
    }
    return 0;
}