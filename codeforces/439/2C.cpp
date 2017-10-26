#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353;
LL C[5005][5005], fac[5005], a, b, c;
LL Solve(LL x, LL y) {
    LL n = min(x, y), ret = 0;
    for(int i = 0; i <= n; ++i) {
        ret = (ret + C[x][i] * C[y][i] % MOD * fac[i] % MOD) % MOD;
    }
    return ret;
}
int main() {
    C[1][0] = C[1][1] = 1;
    for(int i = 2; i <= 5000; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= 5000; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    fac[0] = 1;
    for(int i = 1; i <= 5000; ++i) fac[i] = (fac[i - 1] * i) % MOD;
    cin >> a >> b >> c;
    cout << Solve(a, b) * Solve(a, c) % MOD * Solve(b, c) % MOD << endl;
    return 0;
}

