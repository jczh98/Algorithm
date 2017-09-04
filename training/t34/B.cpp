#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main() {
    LL l, r, w;
    cin >> l >> r >> w;
    LL g = __gcd(r, w);
    r /= g; l /= g; w /= g;
    if(l <= w + r - 2) {
        printf("DEADLOCK\n");
    }else {
        printf("OK\n");
    }
    return 0;
}
