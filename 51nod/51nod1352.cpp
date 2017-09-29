#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Exgcd(LL a, LL b, LL &x, LL &y) {
    if(!b) {x = 1, y = 0; return a;}
    else {LL d = Exgcd(b, a % b, y, x); y-= a / b * x; return d;}
}
int t;
LL a, b, n, ans;
int main() {
    scanf("%d", &t);
    for(; t; t--) {
        scanf("%lld%lld%lld", &n, &a, &b);
        LL x = 0, y = 0;
        LL d = Exgcd(a, b, x, y);
        LL lcm = a * b / d;
        if((n + 1) % d) ans = 0;
        else {
            x *= ((n + 1) / d);
            LL r = b / d;
            x = (x % r + r) % r;
            if(x == 0) x += r;
            if(a * x > n) ans = 0;
            else ans = (n - a * x) / lcm + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}

