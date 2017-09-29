#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL QuickPow(LL a, LL b, LL MOD) {
    LL res = 1;
    for(; b; b >>= 1) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
    }
    return res;
}
LL n, Mod = 1e9 + 7;
int main() {
    cin >> n;
    cout << (((QuickPow(3, n + 1, Mod) - 1 + Mod) % Mod) * QuickPow(2, Mod - 2, Mod)) % Mod << endl;
    return 0;
}
