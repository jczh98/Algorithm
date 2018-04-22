#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
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
int n, m;
string a, b;
Complex A[N << 2], B[N << 2];
int s1[N], s2[N], a1[N], a2[N], a3[N];
int main() {
    scanf("%d%d", &n, &m);
    int L = 1; while(L <= (n + m)) L <<= 1;
    cin >> a >> b;
    for(int i = 0; i < m / 2; ++i) swap(b[i], b[m - 1 - i]);
    // R
    for(int i = 0; i < n; ++i) {
        if(a[i] == 'S') s1[i] = 1; else s1[i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        if(b[i] == 'R') s2[i] = 1; else s2[i] = 0;
    }  
    for(int i = 0; i < L; ++i) A[i] = B[i] = Complex();
    for(int i = 0; i < n; ++i) {
        B[i] = Complex(s1[i]);
    }
    for(int i = 0; i < m; ++i) {
        A[i] = Complex(s2[i]);
    }
    fft(A, L, 1); fft(B, L, 1);
    for(int i = 0; i < L; ++i) A[i] = A[i] * B[i];
    fft(A, L, -1);
    for(int i = 0; i < n; ++i) {
        a1[i] = (int)(A[i + m - 1].r + 0.5);
    }
    // P
    for(int i = 0; i < n; ++i) {
        if(a[i] == 'R') s1[i] = 1; else s1[i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        if(b[i] == 'P') s2[i] = 1; else s2[i] = 0;
    }
    for(int i = 0; i < L; ++i) A[i] = B[i] = Complex();
    for(int i = 0; i < n; ++i) {
        B[i] = Complex(s1[i]);
    }
    for(int i = 0; i < m; ++i) {
        A[i] = Complex(s2[i]);
    }
    fft(A, L, 1); fft(B, L, 1);
    for(int i = 0; i < L; ++i) A[i] = A[i] * B[i];
    fft(A, L, -1);
    for(int i = 0; i < n; ++i) {
        a2[i] = (int)(A[i + m - 1].r + 0.5);
    }
    // S
    for(int i = 0; i < n; ++i) {
        if(a[i] == 'P') s1[i] = 1; else s1[i] = 0;
    }
    for(int i = 0; i < m; ++i) {
        if(b[i] == 'S') s2[i] = 1; else s2[i] = 0;
    }
    for(int i = 0; i < L; ++i) A[i] = B[i] = Complex();
    for(int i = 0; i < n; ++i) {
        B[i] = Complex(s1[i]);
    }
    for(int i = 0; i < m; ++i) {
        A[i] = Complex(s2[i]);
    }
    fft(A, L, 1); fft(B, L, 1);
    for(int i = 0; i < L; ++i) A[i] = A[i] * B[i];
    fft(A, L, -1);
    for(int i = 0; i < n; ++i) {
        a3[i] = (int)(A[i + m - 1].r + 0.5);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        ans = max(ans, a1[i] + a2[i] + a3[i]);
    }
    printf("%d\n", ans);
    return 0;
}