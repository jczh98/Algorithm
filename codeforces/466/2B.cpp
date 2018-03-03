#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k, a, b, now, ans;
int main() {
    cin >> n >> k >> a >> b; now = n;
    if(k == 1) {
        cout << a * (now - 1) << endl;
    }else {
        while(n != 1) {
            if(now < k) {ans += a * (now - 1); break;}
            LL rem = now % k;
            ans += rem * a; now -= rem;
            ans += min(a * (now - now / k), b);
            now /= k;            
        }
        cout << ans << endl;
    }
    return 0;
}