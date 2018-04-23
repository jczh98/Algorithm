#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k, ans;
int main() {
    cin >> n >> k;
    for(LL i = k + 1; i <= n; ++i) {
        if(n % i) {
            ans += (n / i) * (i - k);
            if(n % i >= k) {
                if(k) ans += n % i - k + 1; else ans += n % i;
            }
        }else {
            ans += (n / i) * (i - k);
        }
    }
    cout << ans << endl;
    return 0;
}