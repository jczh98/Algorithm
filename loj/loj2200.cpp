#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int M = 400005;
const double pi = acos(-1.0);
struct Complex{
    double r, i;
    Complex(double r = 0.0, double i = 0.0) : r(r), i(i) {}
    Complex operator + (const Complex &rhs) const { return Complex(r + rhs.r, i + rhs.i); }
    Complex operator - (const Complex &rhs) const { return Complex(r - rhs.r, i - rhs.i); }
    Complex operator * (const Complex &rhs) const { return Complex(r * rhs.r - i * rhs.i, r * rhs.i + i * rhs.r); }
    Complex conj() const { return Complex(r, -i); }
};
inline void rader(Complex * a, int n) {
    for(int i = 1, j = n >> 1; i < n - 1; ++i) {
        if(i < j) swap(a[i], a[j]);
        int k = n >> 1; while(j >= k) {j -= k; k >>= 1;}
        if(j < k) j += k;
    }
}
inline void fft(Complex * a, int n, int type) {
    rader(a, n);
    for(int i = 2; i <= n; i <<= 1) {
        Complex wn(cos(-type * 2 * pi / i), sin(-type * 2 * pi / i));
        for(int j = 0; j < n; j += i) {
            Complex e(1);
            for(int k = j; k < j + (i >> 1); ++k) {
                Complex u = a[k], t = e * a[k + (i >> 1)];
                a[k] = u + t; a[k + (i >> 1)] = u - t; e = e * wn;
            }
        }
    }
    if(type == -1) for(int i = 0; i < n; ++i) a[i].r /= n;
}
int n, len;
double q[M];
Complex f1[M], g[M], f2[M];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%lf", &q[i]);
    for(int i = 1; i <= n; ++i) { f1[i] = Complex(q[i]); g[i] = Complex(1.0 / i / i); }
    len = 1; while(len <= 2 * n) len <<= 1;
    fft(f1, len, 1); fft(g, len, 1);
    for(int i = 0; i < len; ++i) f1[i] = f1[i] * g[i];
    fft(f1, len, -1);
    for(int i = 0; i <= n; ++i) { f2[i] = Complex(q[n - i]);}
    fft(f2, len, 1);
    for(int i = 0; i < len; ++i) f2[i] = f2[i] * g[i];
    fft(f2, len, -1);
    for(int i = 1; i <= n; ++i) {
        printf("%.7f\n", f1[i].r - f2[n - i].r);
    }
    return 0;
}