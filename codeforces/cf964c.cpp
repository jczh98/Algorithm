#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL qpow(LL a, LL b, LL mod) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod; a = (a * a) % mod; b >>= 1;
    }
    return ret;
}    
LL n, a, b, k, ans = 0, MOD = 1e9 + 9;
string s;
int main() {
    cin >> n >> a >> b >> k >> s;
    if(k >= n) {
        for(LL i = 0; i <= n; ++i) {
            if(s[i] == '+') {
                ans = (ans + MOD + (qpow(a, n - i, MOD) * qpow(b, i, MOD) % MOD)) % MOD;
            }else {
                ans = (ans + MOD - (qpow(a, n - i, MOD) * qpow(b, i, MOD) % MOD)) % MOD;
            }
        }
    }else {
        for(LL i = 0; i < k; ++i) {
            if(s[i] == '+') {
                ans = (ans + MOD + (qpow(a, n - i, MOD) * qpow(b, i, MOD) % MOD)) % MOD;
            }else {
                ans = (ans + MOD - (qpow(a, n - i, MOD) * qpow(b, i, MOD) % MOD)) % MOD;
            }
        }
        LL inv_a = qpow(a, MOD - 2LL, MOD);
        LL inv_a_mul_b = inv_a * b % MOD;
        LL akbk = qpow(inv_a_mul_b, k, MOD);        
        if(akbk == 1) {
            ans = (ans * ((n + 1LL) / k)) % MOD;
        }else {
            LL down = (1LL + MOD - akbk) % MOD;
            LL inv_down = qpow(down, MOD - 2, MOD);
            LL up = (1LL + MOD - qpow(inv_a_mul_b, (n + 1LL), MOD)) % MOD;
            LL ret = up * inv_down % MOD;
            ans = ans * ret % MOD;            
        }
    }
    cout << ans << endl;
    return 0;
}