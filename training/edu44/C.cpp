#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k, l, a[100005], ans = 0;
int main() {
    cin >> n >> k >> l;
    for (int i = 0; i < n * k; ++i) cin >> a[i];
    sort(a, a + n * k);
    int pos = upper_bound(a, a + n * k, a[0] + l) - a;
    if (pos < n) {
        cout << 0 << endl;
        return 0;
    }
    int cur = 0, tot = n;
    while (tot < pos - cur) {
        ans += a[cur]; tot--;
        for (int i = 0; i < k; ++i) {
            cur++;
            if (tot == pos - cur) {
                break;
            }
        }
    }
    for (int i = cur; i < pos; ++i) ans += a[i];
    cout << ans << endl;
    return 0;
}