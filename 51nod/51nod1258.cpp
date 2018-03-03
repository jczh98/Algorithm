#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500005;
const LL MOD = 1e9 + 7;
const LL M[3] = {998244353, 1004535809, 469762049};
const LL M1 = 998244353, M2 = 1004535809, M3 = 469762049;
const LL _M = M1 * M2;
LL qpow(LL a, LL b, LL mod) {
    LL ret = 1;
    for(; b; b >>= 1) {
        if(b & 1) ret = (ret * a) % mod; a = (a * a) % mod;
    }
    return ret;
}
const LL inv1 = qpow(M1 % M2, M2 - 2, M2), inv2 = qpow(M2 % M1, M1 - 2, M1), inv12 = qpow(_M % M3, M3 - 2, M3);
int rev[N];
struct NTT {
    LL P, G, num;
    LL w[2][N];
    void init(LL p, LL g, LL m) {
        num = m; P = p; G = g;
        int gg = qpow(G, (P - 1) / num, P);
        w[1][0] = 1; for(int i = 1; i < num; ++i) w[1][i] = 1LL * w[1][i - 1] * gg % P;
        w[0][0] = 1; for(int i = 1; i < num; ++i) w[0][i] = w[1][num - i];
    }
    void dft(int *a, int n, int r) {
        for(int i = 0; i < n; ++i) if(i < rev[i]) swap(a[i], a[rev[i]]);
        for(int i = 1; i < n; i <<= 1) {
            for(int j = 0; j < n; j += (i << 1)) {
                for(int k = 0; k < i; ++k) {
                    int x = a[j + k], y = 1LL * a[j + i + k] * w[r][num / (i << 1) * k] % P;
                    a[j + k] = (x + y) % P; a[j + i + k] = (x - y + P) % P; 
                }
            }
        }
        if(!r) for(int i = 0, inv = qpow(n, P - 2, P); i < n; ++i) a[i] = 1LL * a[i] * inv % P;
    }
}ntt[3];
inline LL mul(LL x, LL y, LL mod) {
    x %= MOD; y %= MOD;
    return (x * y - (LL)((LL)((long double)x / mod * y + 1e-3)) * mod + mod) % mod;
}
inline LL crt(int a1, int a2, int a3) {
    LL A = (mul((LL)a1 * M2 % _M, inv2, _M) + mul((LL)a2 * M1 % _M, inv1, _M)) % _M;
    LL k = ((LL)a3 + M3 - A % M3) * inv12 % M3;
    return (k * (_M % MOD) + A) % MOD;
}
int tmp[N], b2[N], b3[N], B[3][N], c[N];
void polyinv(int *a, int *b, int n) {
    if(n == 1) {b[0] = crt(qpow(a[0], M1, M1 - 2), qpow(a[0], M2, M2 - 2), qpow(a[0], M3, M3 - 2));return;}
    polyinv(a, b, n >> 1);
    int L = 0; while(!((n >> L) & 1)) L++;
    for(int i = 1; i < (n << 1); ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << L);
    for(int i = 0; i < n; ++i) b2[i] = b3[i] = b[i], b2[i + n] = b3[i + n] = 0;
    ntt[0].dft(b, n << 1, 1);
    ntt[1].dft(b2, n << 1, 1);
    ntt[2].dft(b3, n << 1, 1);
    for(int i = 0; i < 3; ++i) {
        int *d = (i == 0 ? b : (i == 1 ? b2 : b3));
        for(int j = 0; j < n; ++j) tmp[j] = a[j], tmp[j + n] = 0;
        ntt[i].dft(tmp, n << 1, 1);
        for(int j = 0; j < (n << 1); ++j) tmp[j] = 1LL * tmp[j] * d[j] % M[i];
        ntt[i].dft(tmp, n << 1, 0);
        for(int j = 0; j < (n << 1); ++j) B[i][j] = tmp[j];
    }
    for(int i = 0; i < (n << 1); ++i) c[i] = crt(B[0][i], B[1][i], B[2][i]), c[i] = (c[i] == 0 ? 0 : MOD - c[i]); 
    c[0] = (c[0] + 2) % MOD;
    for(int i = 0; i < 3; ++i) {
        int *d = (i == 0 ? b : (i == 1 ? b2 : b3));
        for(int j = 0; j < n; ++j) tmp[j] = c[j], tmp[j + n] = 0;
        ntt[i].dft(tmp, n << 1, 1);
        for(int j = 0; j < (n << 1); ++j) tmp[j] = 1LL * tmp[j] * d[j] % M[i];
        ntt[i].dft(tmp, n << 1, 0);
        for(int j = 0; j < (n << 1); ++j) B[i][j] = tmp[j];
    }
    for(int i = 0; i < n; ++i) b[i] = crt(B[0][i], B[1][i], B[2][i]), b[i + n] = 0;
}
int t, k;
LL n, fac[N], inv[N], np[N];
int a[N], b[N], bernoulli[N];
inline LL C(LL n, LL m) { return fac[n] * inv[m] % MOD * inv[n - m] % MOD; }
int main() {
    int m;
    for(m = 1; m <= 50000; m <<= 1);
    for(int i = 0; i < 3; ++i) ntt[i].init(M[i], 3, m << 1);
    fac[0] = 1; for (int i = 1; i <= m + 1; i++) fac[i] = fac[i - 1] * i % MOD;
    inv[1] = 1; for (int i = 2; i <= m + 1; i++) inv[i] = (LL)(MOD - MOD / i) * inv[MOD % i] % MOD;
    inv[0] = 1; for (int i = 1; i <= m + 1; i++) inv[i] = inv[i] * inv[i - 1] % MOD;
    for(int i = 0; i < m; ++i) a[i] = inv[i + 1];
    polyinv(a, b, m);
    for(int i = 0; i < m; ++i) bernoulli[i] = 1LL * b[i] * fac[i] % MOD;
    cout << bernoulli[1] << endl;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        np[0] = 1;
        for(int i = 1; i <= k + 1; ++i) np[i] = np[i - 1] * n % MOD;
        LL ans = (k + 1) * ((MOD + 1) >> 1) % MOD * np[k] % MOD;
        for(int i = 0; i <= k; i += 2) {
            ans += (C(k + 1, i) * bernoulli[i] % MOD * np[k + 1 - i] % MOD) % MOD;
        }
        ans = ans * qpow(k + 1, MOD - 2, MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}