#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7, INV = 5e8 + 4;
LL n;
int main() {
    cin >> n;
    LL r, ans = (n % MOD) * (n % MOD) % MOD;
    for(LL i = 1, last; i <= n; i = last + 1) {
        r = n / i; last = n / r; ans = (ans + MOD - r * (((i + last) % MOD) * ((last - i + 1) % MOD) % MOD * INV % MOD) % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}