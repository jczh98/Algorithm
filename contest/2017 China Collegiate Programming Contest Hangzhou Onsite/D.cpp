#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
int t, n, a[100005];
ll sum[100005];
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        sum[0] = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sum[i] = (sum[i-1] + qpow(i, MOD-2, MOD))%MOD;
        }
        ll ans = 0;
        for(int i = 2; i <= n; ++i) {
            ans += 1LL*a[i]*(1+sum[i-1])%MOD*qpow(n,MOD-2,MOD)%MOD; ans %= MOD;
        }
        ans += a[1]*qpow(n,MOD-2,MOD)%MOD; ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}