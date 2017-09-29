#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Mod = 1e9 + 7;
LL QuickPow(LL a, LL b, LL MOD) {
    LL res = 1;
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
LL t, p, q, k;
int main() {
    cin >> t;
    while(t--) {
        cin >> p >> q >> k;
        LL pre = QuickPow(2, Mod - 2, Mod);
        LL up = QuickPow(p - 2LL * q, k, Mod), down = QuickPow(p, k, Mod);
        down = (down * 2) % Mod;
        LL inv_down = QuickPow(down, Mod - 2, Mod);
        LL suf = up * inv_down % Mod;
        LL ans = (pre + suf) % Mod;
        cout << ans << endl;
    }
    return 0;
}

