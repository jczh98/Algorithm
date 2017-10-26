#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL f[5005][5005], a, b, c;
const LL MOD = 998244353;
int main() {
    for(int i = 0; i <= 5000; ++i) f[i][0] = f[0][i] = 1;
    for(int i = 1; i <= 5000; ++i) {
        for(int j = 1; j <= 5000; ++j) {
            f[i][j] = (f[i - 1][j] + j * f[i - 1][j - 1]) % MOD;
        }
    }
    cin >> a >> b >> c;
    cout << f[a][b] * f[a][c] % MOD * f[b][c] % MOD << endl;
    return 0;
}

