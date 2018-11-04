#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int N = 500010;
int prime[N+5], check[N+5], tot;
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = (ret*a) % mod;
        a = (a*a) % mod; b >>= 1;
    }
    return ret;
}
void sieve() {
    memset(check, 0, sizeof(check)); tot = 0;
    for(int i = 2; i <= N; ++i) {
        if(!check[i]) {
            prime[tot++] = i;
        }
        for(int j = 0; j < tot; ++j) {
            if(i * prime[j] > N) break;
            check[i*prime[j]] = 1;
            if(i % prime[j] == 0) {
                break;
            }
        }
    }
}
int factor[N];
int primitive_root(ll p) {
    if(p == 2) return p;
    ll x = p - 1; int cnt = 0;
    for(int i = 0; 1LL*prime[i]*prime[i]<=x; ++i) {
        if(x%prime[i]==0) {
            factor[cnt++]=prime[i];
            while(x%prime[i]==0) x /= prime[i];
        }
    }
    if(x > 1) factor[cnt++] = x;
    for(int g = 2; g < p; ++g) {
        int flag = 1;
        for(int i = 0; i < cnt; ++i) {
            if(qpow(g, (p-1)/factor[i], p) == 1LL) {flag = 0; break;}
        }
        if(flag) return g;
    }
    return 0;
}
bool checkf(int g, int p) {
    for (int i = 1; i < p - 1; i++)
        if (qpow(g, i, p) == 1) return false;
    return true;
}
int n, p, id[N], cnt[N+5], x, zeros = 0, a[N+5], gp[N+5];
ll ans[N+5];
Complex b[N+5];
int main() {
    sieve();
    scanf("%d%d", &n, &p);
    int g = primitive_root(p);
    ll t = 1;
    for(int i = 0; i < p - 1; ++i) {
        id[t] = i; t=(t*g)%p;
    }
    //int g = 2;
    // for (; !checkf(g, p); g++);
    // gp[0] = 1;
    // for (int i = 1; i < N; i++) gp[i] = 1LL * gp[i - 1] * g % p;
    // for (int i = 0; i < p - 1; i++) id[gp[i]] = i;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if(a[i] % p == 0) zeros++;
        else cnt[id[a[i]%p]]++;
    }
    int len = 1;
    while(len < 2*p) len<<=1;
    for(int i = 0; i < len; ++i) b[i] = Complex(cnt[i], 0);
    fft(b, len, 1);
    for(int i = 0; i < len; ++i) b[i] = b[i]*b[i];
    fft(b, len, -1);
    for(int i = 0; i < len; ++i) ans[i%(p-1)] += (ll)(b[i].r+0.5);
    for(int i = 1; i <= n; ++i) {
        if(a[i] >= p) printf("0\n");
        else if(a[i] % p == 0) {
            printf("%lld\n", 2LL*zeros*(n-zeros)+1LL*zeros*zeros);
        }else {
            printf("%lld\n", ans[id[a[i]]]);
        }
    }
    return 0;
}