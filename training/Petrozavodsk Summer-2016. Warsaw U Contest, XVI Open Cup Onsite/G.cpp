#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL k, a, b, ans = 0;
bool Judge(LL x, LL n) {
    LL t, res = 0;
    while(n) {
        t = n % 10;
        res += t * t;
        n /= 10;
    }
    return res == x;
}
int main() {
    cin >> k >> a >> b;
    for(LL i = 1; i <= 81 * 18; i++) {
        if(k * i > b) break;
        if(k * i >= a && k * i <= b) {
            if(Judge(i, k * i)) {
                ans ++;
            }

        }
    }
    cout << ans << endl;
    return 0;
}

