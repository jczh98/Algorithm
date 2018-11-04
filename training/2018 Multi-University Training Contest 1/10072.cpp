#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define ll long long
const ll mod = 1e9 + 7;
using namespace std;
ll n, c[100005], ans, d[100005];
int t;
int main() {
    c[1] = 2; c[0] = 1;
    rep(i,2,63)c[i]=(c[i-1]*2%mod+(((1LL<<(i-2))%mod)*(((1LL<<(i-1))+1)%mod))%mod-1)%mod;
    d[0] = 1; d[1] = 1;
    rep(i, 2, 63) d[i] = (1LL << (i - 1)) % mod;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        ans = 0;
        if (n == 1) {
            printf("1\n");
            continue;
        }
        while (n > 1) {
            int i = log((double)(n + 0.5) * 1.0) / log(2.0);
            ans += c[i] % mod;
            ans %= mod;
            n -= (1LL<<i);
            if (!n) break;
            ans += n % mod * d[i] % mod;
            ans %= mod;
            n++; ans--;
            ans = (ans + mod) % mod;
        }
        if (n == 1) ans = (ans + 1) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}