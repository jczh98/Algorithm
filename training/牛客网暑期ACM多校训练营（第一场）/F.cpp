#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
LL pre = 1, ans = 0;
inline LL qpow(LL a, LL b, LL mod) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD; b >>= 1;
    }
    return ret;
}
const int N = 10005;
LL inv[N], buf[N];
inline void init(int d) {
    inv[1] = 1;
    for (int i = 2; i < d; ++i) inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
}
inline LL lagrange(LL *vals, LL d, LL x) { // d for deg + 1, x for required value
    if(x < d) return vals[x];
    LL tmp = 1, ret = 0;
    for (int i = 1; i < d; ++ i) {
        tmp = tmp * (x - i + 1) % MOD * inv[i] % MOD;
        buf[i] = tmp * vals[i] % MOD;
    }
    tmp = 1; ret = buf[d - 1];
    for (int i = d - 2; i >= 0; -- i) {
        tmp = (MOD - tmp) * inv[d - 1 - i] % MOD * (x - i - 1) % MOD;
        ret = (ret + buf[i] * tmp % MOD) % MOD;
    }   
    return ret;
}
int a[10005], n;
LL vals[10005];
int main() {
    init(10000);
    while(scanf("%d", &n) == 1) {
        ans = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + 1 + n);
        a[0] = 0; pre = 1;
        for(int i = 1; i <= n; ++i) { 
            if(a[i] == a[i - 1]) {
                pre = pre * 1LL * a[i] % MOD; continue;
            }
            vals[0] = 0;
            for(int j = 1; j <= n - i + 2; ++j) {
                vals[j] = vals[j - 1];
                vals[j] = (vals[j] + j * (qpow(j, n - i + 1, MOD) + MOD - qpow(j - 1, n - i + 1, MOD)) % MOD) % MOD;
            }
            ans = (ans + pre * (lagrange(vals, n - i + 3, a[i]) + MOD - lagrange(vals, n - i + 3, a[i - 1])) % MOD ) % MOD;
            pre = pre * 1LL * a[i] % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}