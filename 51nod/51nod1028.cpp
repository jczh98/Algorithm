#include <bits/stdc++.h>
#define pi acos(-1.0)
using namespace std;
const int MAXN = 300010;
template<typename T>
void Print(T x) {
    static char s[33], *s1; s1 = s;
    if (!x) *s1++ = '0';
    if (x < 0) putchar('-'), x = -x;
    while(x) *s1++ = (x % 10 + '0'), x /= 10;
    while(s1-- != s) putchar(*s1);
}
struct Complex{
    double r, i;
    Complex(double r = 0, double i = 0) : r(r), i(i) {}
    Complex operator + (const Complex &rhs) const { return Complex(r + rhs.r, i + rhs.i); }
    Complex operator - (const Complex &rhs) const { return Complex(r - rhs.r, i - rhs.i); }
    Complex operator * (const Complex &rhs) const { return Complex(r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r); }
    Complex conj() const { return Complex(r, -i); }
}ca[MAXN], cb[MAXN], A, B;
int res[MAXN], bit_rev[MAXN], N, P;
inline void FFT_init(int n1, int n2) {
    for(P = 0, N = 2; N < n1 + n2; ++P, N <<= 1);
    for(int i = 1; i < N; ++i) bit_rev[i] = (bit_rev[i >> 1] >> 1) | ((i & 1) << P);
}
inline void FFT(Complex *a, int type) {
    for (int i = 0; i < N; ++i) if (i > bit_rev[i]) std::swap(a[i], a[bit_rev[i]]);
    for (int i = 1; i < N; i <<= 1) {
        Complex omega(cos(pi / i), sin(pi / i) * type);
        for (int j = 0; j < N; j += i << 1) {
            Complex e(1), *b = a + j, *c = b + i;
            for (int k = 0; k < i; ++k, e = e * omega) {
                A = b[k]; B = c[k] * e; b[k] = A + B; c[k] = A - B;
            }
        }
    }
    if (type == -1) for(int i = 0; i < N; i++) a[i].r /= N;
}
inline void Convolution(int a[], int na, int b[], int nb) {
    for(int i = 0; i < na; ++i) ca[i].r = a[i], ca[i].i = 0;
    for(int i = 0; i < nb; ++i) cb[i].r = b[i], cb[i].i = 0;
    FFT_init(na, nb);
    FFT(ca, 1); FFT(cb, 1);
    for(int i = 0; i < N; ++i) ca[i] = ca[i] * cb[i];
    FFT(ca, -1);
    for(int i = 0; i < N; ++i) res[i] = ca[i].r + 0.5;
}
char a[MAXN], b[MAXN];
int aa[MAXN], bb[MAXN], l1, l2, l;
int main() {
    scanf("%s%s", a, b); l1 = strlen(a); l2 = strlen(b);
    for(int i = 0; i < l1; ++i) aa[i] = a[l1 - i - 1] - '0';
    for(int i = 0; i < l2; ++i) bb[i] = b[l2 - i - 1] - '0';
    Convolution(aa, l1, bb, l2);
    for(int i = 1; i < N; ++i) res[i] += res[i - 1] / 10, res[i - 1] %= 10;
    while(N && !res[N]) N--;
    for(int i = N; i >= 0; i--) Print(res[i]); printf("\n");
    return 0;
}