#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline LL quickpow(LL a, LL b, LL MOD) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ret;
}
inline LL mod(LL a, LL MOD) {return a % MOD;}
LL n, m, k, MOD = 1000000007;
LL MOD2 = MOD - 1;
int main() {
    cin >> n >> m >> k;
    if(((n + m) & 1) && k == -1) cout << 0 << endl;
    else cout << quickpow(2, (mod(n-1,MOD2)*mod(m-1,MOD2))%MOD2+MOD2,MOD) << endl;
    return 0;
}