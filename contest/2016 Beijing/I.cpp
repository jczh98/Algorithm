#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007, N = 200;
int t;
int n, k;
ll sum[500005], sumk[50005][105], pow_sum[50005][105];
char s[500005];
inline ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
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
inline ll C(ll n, ll m, ll mod) {
    return fac[n]*finv[m]%mod*finv[n-m]%mod;
}
int main() {
    precalc();
    scanf("%d", &t);
    while(t--) {
        memset(pow_sum, 0, sizeof(pow_sum));
        scanf("%d%d%s", &n, &k, s);
        int len = strlen(s);
        sum[0] = 0;
        for(int i = 0; i < len; ++i) {
            sum[i+1] = (sum[i] + s[i] - '0') % MOD;
        }
        for(int i = 0; i <= n; ++i) {
            pow_sum[i][0] = 1;
            for(int l = 1; l <= k; ++l) {
                pow_sum[i][l] = pow_sum[i][l-1] * sum[i] % MOD;
            }
        }
        for(int i = 0; i <= k; ++i) {
            sumk[0][i] = 0;
            for(int j = 1; j <= n; ++j) {
                sumk[j][i] = (sumk[j-1][i] + pow_sum[j-1][i])%MOD;
            }
        }
        for(int i = 1; i <= n; ++i) {
            ll ans = 0;
            for(int l = 0; l <= k; ++l) {
                if((k-l)&1) {
                    ans = (ans - C(k,l,MOD)*pow_sum[i][l]%MOD*sumk[i][k-l]%MOD+MOD)%MOD;
                }else {
                    ans = (ans + C(k,l,MOD)*pow_sum[i][l]%MOD*sumk[i][k-l]%MOD)%MOD;
                }
            }
            printf("%lld%c", ans, i==n?'\n':' ');
        }
    }
    return 0;
}