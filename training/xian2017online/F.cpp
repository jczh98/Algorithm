#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const LL Mod = 998244353;

LL QuickPow(LL a, LL b, LL MOD) {
    LL res = 1;
    while (b) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

LL Inv(LL x, LL MOD) {
    return QuickPow(x, MOD - 2, MOD);
}

LL C(LL n, LL m, LL MOD) {
    if (m > n) return 0LL;
    LL up = 1LL, down = 1LL;
    for (LL i = n - m + 1; i <= n; i++) up = (up * i) % MOD;
    for (LL i = 1; i <= m; i++) down = (down * i) % MOD;
    return (up * Inv(down, MOD)) % MOD;
}

LL Lucas(LL n, LL m, LL MOD) {
    if (m > n) return 0LL;
    LL ans = 1;
    for (; m; m /= MOD, n /= MOD) {
        ans = (ans * C(n % MOD, m % MOD, MOD)) % MOD;
    }
    return ans;
}

LL n, m;

int main() {
    while (cin >> n >> m) {
        if (n < m || (n + m) % 2 == 1) {
            cout << 0 << endl;
            continue;
        }
        if (m == 0 && n % 2 == 0) {
            if ((n / 2) & 1) cout << (-1 + Mod) % Mod << endl;
            else cout << 1 << endl;
            continue;
        }
        LL temp;
        if (((n + m) / 2 + m) % 2 == 1) temp = -1;
        else temp = 1;
        LL bin = Lucas((n + m) / 2 - 1, m - 1, Mod);
        LL inv = QuickPow(m, Mod - 2, Mod);
        LL ans = QuickPow(2, m - 1, Mod) * n % Mod;
        ans = (ans * bin) % Mod;
        ans = (ans * inv) % Mod;
        ans = (ans * temp + Mod) % Mod;
        ans = (ans + Mod) % Mod;
        cout << ans << endl;
    }
    return 0;
}

