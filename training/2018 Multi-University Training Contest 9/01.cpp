#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 7000;
ll finv[N], fac[N], inv[N];
ll euler(ll n) {
    ll res = n, a = n;
    for (ll i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            res = res / i * (i - 1);
            while (a % i == 0) a /= i;
        }
    }
    if (a > 1) res = res / a * (a - 1);
    return res;
}
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = (ret*a) % mod;
        a = (a*a)%mod; b>>=1;
    }
    return ret;
}
void calc(ll mod) {
    fac[0] = 1; 
    for(ll i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    finv[0] = 1;
    ll phi = euler(mod);
    for(ll i = 1; i < N; ++i) {
        finv[i] = qpow(fac[i], phi-1, mod);
    }
}
ll C(ll n, ll m, ll mod) {
    return fac[n]*finv[m]%mod*finv[n-m]%mod;
}
ll t, n, m, k, ans;
int main() {
    scanf("%d", &t);
    ll ans = 1;
    while(t--) {
        cin >> n >> m >> k;
        calc(k);
        ll phi = euler(k);
        cout << fac[n*m]*n%k*fac[m]%k*fac[n-1]%k << endl;
        if(finv[n+m-1] == 0) {
            ans = fac[n*m]*n%k*fac[m]%k*fac[n-1]%k/fac[n+m-1];
        }else {
            ans = fac[n*m]*n%k*fac[m]%k*fac[n-1]%k*finv[n+m-1]%k;
        }
        cout << ans << endl;
    }
    return 0;
}