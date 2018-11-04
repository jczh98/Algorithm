#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7, m = (1<<19);
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
ll inv = qpow(2, MOD-2, MOD);
void fwt_xor(ll *a, int n) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                ll x = a[i + j], y = a[i + j + d];
                a[i + j] = (x + y) % MOD;
                a[i + j + d] = (x - y + MOD) % MOD;
            }
}
void ufwt_xor(ll *a, int n) {
    for (int d = 1; d < n; d <<= 1)
        for (int m = d << 1, i = 0; i < n; i += m)
            for (int j = 0; j < d; j++) {
                ll x = a[i + j], y = a[i + j + d];
                a[i + j] = (x + y) * inv % MOD;
                a[i + j + d] = ((x - y) * inv % MOD + MOD) % MOD;
            }
}
int n, x, XOR = 0;
ll f[100][600005];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &x); f[0][x] = 1;
        XOR^=x;
    }
    if(!XOR) {
        cout << n << endl;
        return 0;
    }
    if(f[0][XOR]) {
        cout << n - 1 << endl;
        return 0;
    }
    fwt_xor(f[0], m);
    for(int i = 1; i <= 19; ++i) {
        for(int j = 0; j < m; ++j) f[i][j] = f[i-1][j]*f[0][j]%MOD;
    }
    for(int i = 1; i <= 19; ++i) {
        ufwt_xor(f[i], m);
        if(f[i][XOR]) {
            cout << n - i - 1<< endl;
            return 0;
        }
    }
    return 0;
}