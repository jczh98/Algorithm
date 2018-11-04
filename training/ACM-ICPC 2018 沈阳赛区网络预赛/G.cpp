#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ll a[10000];
const int N = 10000000, MOD = 1e9+7;
bool check[N+5];
int prime[N+5], mu[N+5], tot;
void mobius() {
    memset(check, 0, sizeof(check));
    mu[1] = 1; tot = 0;
    for(int i = 2; i <= N; ++i) {
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
ll getmu(ll x) {
    if(x <= N) return mu[x];
    ll v = 1;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0) {
            v = -v;
            x /= i;
            if (x % i == 0) return 0;
        }
    if (x != 1) v = -v;
    return v;
}
ll n, m, inv6 = 166666668;
ll f(ll x, ll y) {
    ll ret = x;
    ret = ret*y%MOD;
    ret = ret*(1+y)%MOD;
    ret = ret*(3+x+2LL*x*y%MOD)%MOD;
    ret = ret*inv6%MOD;
    return ret;
}
int main() {
    mobius();
    while(scanf("%lld%lld", &n, &m) != EOF) {
        ll ans = 0;
        int sqr = sqrt(m);
        for(ll i = 1; i * i <= m; ++i) {
            if(m % i == 0) {
                ans = (ans + getmu(i) * f(i, n / i)+ MOD)%MOD;
                if(i != m / i) ans = (ans + getmu(m/i) * f(m / i, n/(m/i))+ MOD)%MOD;
            }
        }
        printf("%lld\n", ans);     
    }
    return 0;
}