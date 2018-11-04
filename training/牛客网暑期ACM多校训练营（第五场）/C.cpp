#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c, n;
int main() {
    cin >> c >> n;
    ll mx = n / c;
    if(n / c == 1) {
        printf("%lld\n", c * c);
    }else if(n / c > 1) {
        printf("%lld\n", mx * c * (mx - 1) * c);
    }else {
        printf("-1\n");
    }
    return 0;
}