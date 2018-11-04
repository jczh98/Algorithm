#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
ll qpow(ll a, ll b, ll mod) {
    if(a == 0) return 0;
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
ll Inv(ll x, ll mod) {
    return qpow(x, mod -2 , mod);
}
ll C(ll n, ll m, ll mod) {
    if(m > n) return 0LL;
    ll up = 1LL, down = 1LL;
    for(ll i = n - m + 1; i <= n; i++) up = (up * i) % mod;
    for(ll i = 1; i <= m; i++) down = (down * i) % mod;
    return (up * Inv(down, mod)) % mod;
}
ll Lucas(ll n, ll m, ll mod) {
    if(m > n) return 0LL;
    ll ans = 1;
    for(; m; m /= mod, n /= mod) {
        ans = (ans * C(n % mod, m % mod, mod)) % mod;
    }
    return ans;
}
ll n, m, k;
int t;
int main() {
    scanf("%d", &t);
    for(int kase = 1; kase <= t; ++kase) {
        cin >> n >> m >> k;
        printf("Case #%d: ", kase);
        if(k == 1) {
            if(n == 1) {
                cout << m << endl;
            } else {
                cout << 0 << endl;
            }
            continue;
        }
        if(k == 2) {
            cout << Lucas(m,k,MOD)*k%MOD*qpow(k-1,n-1,MOD)%MOD << endl;
            continue;
        }
        ll ans = 0;
        ll binomal = k;
        for(int i = k - 1; i >= 0; --i) {
            int op = (i&1)?-1:1;
            ans += op*binomal*(k-i)%MOD*qpow(k-i-1,n-1,MOD)%MOD;
            //cout << binomal*(k-i)%MOD*qpow(k-i-1,n-1,MOD)%MOD << endl;
            if(op<0) ans += MOD, ans %= MOD;
            ans %= MOD;
            binomal = binomal*(k-(k-i+1)+1)%MOD*qpow((k-i+1),MOD-2,MOD)%MOD;
        }
        cout << ans * Lucas(m,k,MOD)%MOD << endl;
    }
}