#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 100005, P = 663224321, G = 3;
inline LL qpow(LL a, LL b, LL mod) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
int w[2][N << 2], tot;
inline void pre(int n) {
    tot = n;
    LL g = qpow(G, (P - 1) / n, P), invg = qpow(g, P - 2, P);
    w[0][0] = w[1][0] = 1;
    for(int i = 1; i < n; ++i) {
        w[0][i] = w[0][i - 1] * g % P;
        w[1][i] = w[1][i - 1] * invg % P;
    }
}
inline void ntt(LL *x, int n, int r) { // zero for ntt and one for inverse
    for(int i = 0, j = 0; i < n; ++i) {
        if(i > j) swap(x[i], x[j]);
        for(int l = n >> 1; (j ^= l) < l; l >>= 1);
    }
    for(int i = 2; i <= n; i <<= 1) {
        int m = i >> 1;
        for(int j = 0; j < n; j += i) {
            for(int k = 0; k < m; ++k) {
                LL z = x[j + m + k] * w[r][tot / i * k] % P;
                x[j + m + k] = (x[j + k] - z + P) % P;
                x[j + k] = (x[j + k] + z) % P;
            }
        }
    }
    if(r) for(int i = 0, inv = qpow(n, P - 2, P); i < n; ++i) x[i] = x[i] * inv % P;
}
void poly_inverse(int n, LL *a, LL *b, LL *tmp) {
    if(n == 1) {b[0] = qpow(a[0], P - 2, P); return;}
    poly_inverse((n + 1) >> 1, a, b, tmp);
    int len = 1; while(len < (n << 1)) len <<= 1;
    for(int i = 0; i < n; ++i) tmp[i] = a[i];
    for(int i = n; i < len; ++i) tmp[i] = 0;
    ntt(tmp, len, 0); ntt(b, len, 0);
    for(int i = 0; i < len; ++i) {
        b[i] = (2 - tmp[i] * b[i] % P + P) % P * b[i] % P;
    }
    ntt(b, len, 1);
    for(int i = n; i < len; ++i) b[i] = 0;
}
LL a[N << 2], b[N << 2], tmp[N << 2], n, m, t;
int main() {
    scanf("%d", &t);
    m = 1; while(m <= N) m <<= 1; pre(m << 1);
    a[0] = 1; a[1] = -1;
    for(int i = 2; i < N; ++i) {
        a[i] = qpow(i - 1, i - 2, P);
        a[i] = (P - a[i]) % P;
    }
    poly_inverse(m, a, b, tmp);
    while(t--) {
        scanf("%d", &n);
        cout << b[n] << endl;
    }
    return 0;
}