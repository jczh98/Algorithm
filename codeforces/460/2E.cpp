#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a, b, p, x, ans = 0;
LL quick_pow(LL x, LL y, LL mod) {
    LL ret = 1;
    for(; y; y >>= 1) {
        if(y & 1) ret = (ret * x) % mod;
        x = (x * x) % mod;
    }
    return ret;
}
int main() {
    cin >> a >> b >> p >> x;
    for(LL i = 1; i < p; ++i) {
        LL inv = quick_pow(quick_pow(a, i, p), p - 2, p);
        LL y = b * inv % p;
        LL P = p * (p - 1);
        LL r = (p * i + (p - 1) * (p - 1) % P * y) % P;
        ans += x / P + (x % P >= r);
    }
    cout << ans << endl;
    return 0;
}