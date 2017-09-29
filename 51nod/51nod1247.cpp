#include <bits/stdc++.h>
using namespace std;
// proof: (a, b)->(b, a); (a, b)->(a % b, b)->(b, a % b)
int t;
long long a, b, x, y;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
        if(__gcd(a, b) == __gcd(x, y)) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}
