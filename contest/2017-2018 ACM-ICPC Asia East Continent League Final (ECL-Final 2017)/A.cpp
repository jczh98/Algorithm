#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL n, k, ans, MOD = 1e9 + 7;
LL qpow(LL a, LL b, LL p) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % p;
        a = (a * a) % p; b >>= 1;
    }
    return ret;
}
int main() {
    scanf("%d", &t);
    for(int kase = 1; kase <= t; ++kase) {
        cin >> n >> k;
        LL comb = 1; ans = 0;
        LL tot = qpow(2, n, MOD);
        for(LL i = 0; i < k; ++i) {
            ans = (ans + comb) % MOD;
            comb = ((comb * (n - i)) % MOD * qpow(i + 1, MOD - 2, MOD)) % MOD;
        }
        cout << "Case #" << kase << ": " << (tot - ans + MOD) % MOD << endl;
    }
    return 0;
}