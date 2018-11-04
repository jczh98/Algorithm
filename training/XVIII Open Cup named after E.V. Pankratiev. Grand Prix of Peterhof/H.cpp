#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define rep(i, j) for (int i = 0, i##_end_ = (j); i < i##_end_; ++ i)
#define For(i, j, k) for (int i = (j), i##_end_ = (k); i <= i##_end_; ++ i)
#define Fordown(i, j, k) for (int i = (j), i##_end_ = (k); i >= i##_end_; -- i)
#define Set(a, b) memset(a, b, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define x first
#define y second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define SZ(a) ((int)(a).size())
#define INF (0x3f3f3f3f)
#define INF1 (2139062143)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define y1 wozenmezhemecaia

template <typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }

inline int read() {
    static int _, __; static char c_;
    for (_ = 0, __ = 1, c_ = getchar(); c_ < '0' || c_ > '9'; c_ = getchar()) if (c_ == '-') __ = -1;
    for ( ; c_ >= '0' && c_ <= '9'; c_ = getchar()) _ = (_ << 1) + (_ << 3) + (c_ ^ 48);
    return _ * __;
}

const int MOD = 998244353, g0 = 3, maxn = 1e5 + 5;

int rev[maxn << 2], powg[maxn << 2], ipowg[maxn << 2], ig0, invn;

inline int ad(int x, int y) { if ((x += y) >= MOD) return x - MOD; return x; }

inline LL Pow(LL a, LL b) {
    static LL Ans;
    for (Ans = 1; b; b >>= 1, (a *= a) %= MOD) if (b & 1) (Ans *= a) %= MOD;
    return Ans;
}

inline void Init(int N) {
    ig0 = Pow(g0, MOD - 2);
    for (int i = 1; i <= N; i <<= 1)
        powg[i] = Pow(g0, (MOD - 1) / i), ipowg[i] = Pow(ig0, (MOD - 1) / i);
}

inline void pre(int n) {
    static int N, cnt;
    for (N = 1, cnt = 0; N < n; N <<= 1, ++ cnt);
    rep(i, n) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
    invn = Pow(n, MOD - 2);
}

inline void NTT(int* a, int n, int ty) {
    rep(i, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int i = 2, p = 1; i <= n; p = i, i <<= 1) {
        int w0 = ty > 0 ? powg[i] : ipowg[i];
        for (int j = 0; j < n; j += i) {
            int w = 1;
            rep(k, p) {
                int x = a[j + k], y = (LL)a[j + k + p] * w % MOD;
                a[j + k] = ad(x, y), a[j + k + p] = ad(x, MOD - y);
                w = (LL)w * w0 % MOD;
            }
        }
    }
    if (ty < 1) rep(i, n) a[i] = (LL)a[i] * invn % MOD;
}

namespace Mult {
    static int A[maxn << 2], B[maxn << 2];
    inline void Mult(int* a, int* b, int* c, int n) {
        rep(i, n) A[i] = a[i], B[i] = b[i];
        pre(n), NTT(A, n, 1), NTT(B, n, 1);
        rep(i, n) A[i] = (LL)A[i] * B[i] % MOD;
        NTT(A, n, -1);
        rep(i, n) c[i] = A[i];
    }
}

namespace Inv {
    static int A[maxn << 2], B[maxn << 2], a[maxn << 2];
    void Inv_(int* b, int n) {
        if (n == 1) { b[0] = Pow(a[0], MOD - 2); return; }
        Inv_(b, n >> 1);
        rep(i, n) A[i] = a[i], B[i] = b[i];
        For(i, n, n << 1) A[i] = B[i] = 0;
        pre(n << 1), NTT(A, n << 1, 1), NTT(B, n << 1, 1);
        rep(i, n << 1) A[i] = (LL)A[i] * B[i] % MOD * B[i] % MOD;
        NTT(A, n << 1, -1);
        rep(i, n) b[i] = ad(ad(b[i], b[i]), MOD - A[i]);
    }
    inline void Inv(int* x, int* y, int n) {
        rep(i, n) a[i] = x[i], y[i] = 0;
        Inv_(y, n);
    }
}

inline void Int(int* a, int* b, int n) {
    Fordown(i, n - 1, 0) b[i + 1] = Pow(i + 1, MOD - 2) * a[i] % MOD;//downto!!!
    b[0] = 0;
}

inline void Der(int *a, int* b, int n) {
    rep(i, n) b[i] = (LL)a[i + 1] * (i + 1) % MOD;
}

namespace Ln {
    static int A[maxn << 2], B[maxn << 2];
    inline void Ln(int* a, int* b, int n) {
        rep(i, n) A[i] = B[i] = a[i];
        For(i, n, n << 1) A[i] = B[i] = 0;
        Inv:: Inv(A, A, n), Der(B, B, n << 1);
        Mult:: Mult(A, B, A, n << 1), Int(A, A, n << 1);
        rep(i, n) b[i] = A[i];
    }
}

int main()
{
    static int f[maxn << 2], g[maxn << 2], h[maxn << 2], n, N, k, m;

    for (n = read(), m = read(), k = read(), N = 1; N < n; N <<= 1);
    Init(N << 1);
    rep(i, n) f[i] = read();
    rep(i, m) g[i] = read();
    Mult::Mult(f, g, h, N);
    Ln::Ln(h, h, N);
    rep(i, k) printf("%d ", h[i]);
    return 0;
}