#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL qpow(LL a, LL b, LL mod) {
    LL ret = 1;
    for(; b; b >>= 1) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod;
    }
    return ret;
}
double bbp(int n, int co, int k) {
    double ret = 0;
    for(int i = 0; i <= n; ++i) {
        ret += qpow(16, n - i, 8 * i + co) * 1.0 / (8 * i + co);
    }
    for(int i = n + 1; i <= n + 1000 + 1; ++i) {
        ret += powf(16, n - i) * 1.0 / (8 * i + co);
    }
    return k * ret;
}
int t, n;
double ans = 0;
int main() {
    scanf("%d", &t);
    for(int kase = 1; kase <= t; ++kase) {
        scanf("%d", &n); n--;
        ans = bbp(n, 1, 4) - bbp(n, 4, 2) - bbp(n, 5, 1) - bbp(n, 6, 1);
        ans = ans - (int) ans;
        if(ans < 0) ans += 1;
        int out = ans * 16;
        printf("Case #%d: %d ", kase, n + 1);
        if(out < 10) {
            printf("%d\n", out);
        }else {
            printf("%c\n", out + 55);
        }
    }
    return 0;
}