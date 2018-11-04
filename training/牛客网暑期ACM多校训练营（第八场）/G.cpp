#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll ans, n;
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = (a * ret) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
//a(n) = (24 - 42n + 23n^2 - 6n^3 + n^4)/24.
int main() {
    cin >> n;
    ans = 24;
    ans = (ans - 42LL * n % MOD + MOD) % MOD;
    ans = (ans + 23LL * n % MOD * n % MOD) % MOD;
    ans = (ans - 6LL * n % MOD * n % MOD * n % MOD + MOD) % MOD;
    ans = (ans + n * n % MOD * n % MOD * n % MOD) % MOD;
    ans = ans * qpow(24LL, MOD - 2, MOD) % MOD;
    cout << ans << endl;
    return 0;
}