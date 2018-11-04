#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, a[100005], ans = 0, k;
LL Gcd(LL x, LL y) {
    return !y ? x : Gcd(y, x % y);
}
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int t = 1; t <= 200; ++t) {
        random_shuffle(a + 1, a + 1 + n);
        LL gcd = a[1], cnt = k;
        for(int i = 1; i <= n; ++i) {
            LL tmp = Gcd(gcd, a[i]);
            if(tmp <= ans) cnt--; else gcd = tmp;
            if(cnt < 0) break;
        }
        if(cnt >= 0) ans = max(gcd, ans);
    }
    cout << ans << endl;
    return 0;
}