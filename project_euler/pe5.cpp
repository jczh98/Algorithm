#include <bits/stdc++.h>
#define MAXN 50005
using namespace std;
typedef long long LL;
LL k, c[MAXN], m[MAXN];
void Exgcd(LL a, LL b, LL &d, LL &x, LL &y) {
    if (!b)d = a, x = 1, y = 0;
    else Exgcd(b, a % b, d, y, x), y -= x * (a / b);
}
LL Inv(LL a, LL p) {
    LL d, x, y;
    Exgcd(a, p, d, x, y);
    return (x + p) % p == 0 ? p : (x + p) % p;
}
int main() {
    LL m1, m2, c1, c2;
    k = 20;
    for (int i = 1; i <= k; i++)
        m[i] = i, c[i] = 0;
    for (int i = 2; i <= k; i++) {
        m1 = m[i - 1], m2 = m[i], c1 = c[i - 1], c2 = c[i];
        LL t = __gcd(m1, m2);
        if ((c2 - c1) % t != 0) {
            c[k] = -1;
            break;
        }
        m[i] = m1 * m2 / t;
        c[i] = Inv(m1 / t, m2 / t) * ((c2 - c1) / t) % (m2 / t) * m1 + c1;
        c[i] = (c[i] % m[i] + m[i]) % m[i];
    }
    if(c[k] <= 0) c[k] += m[k];
    printf("%lld\n", c[k]);
    return 0;
}