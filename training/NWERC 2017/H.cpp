#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[3], d, ans;
int main() {
    cin >> a[0] >> a[1] >> a[2] >> d;
    for(int i = 0; i <= d; ++i) {
        for(int j = 0; j <= d && i + j <= d; ++j) {
            int k = d - i - j;
            a[0] += i; a[1] += j; a[2] += k;
            ans = a[0] * a[0] + a[1] * a[1] + a[2] * a[2] + 7 * min(min(a[0], a[1]), a[2]);
            a[0] -= i; a[1] -= j; a[2] -= k;
            cout << i << " " << j << " " << k << " " << ans << endl;
        }
    }
    return 0;
}