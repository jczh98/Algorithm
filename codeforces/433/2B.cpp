#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n, k, ans1, ans2;
int main() {
    cin >> n >> k;
    if (n == k || k == 0) {
        ans1 = 0;
    } else {
        ans1 = 1;
    }
    if (n % 3 == 0) {
        if (k <= n / 3) {
            ans2 = 2 * k;
        } else {
            ans2 = n - k;
        }
    } else if (n % 3 == 1) {
        if (k <= n / 3) {
            ans2 = 2 * k;
        } else if (k == n / 3 + 1) {
            ans2 = n / 3 * 2;
        } else if (k > n / 3 + 1) {
            ans2 = n - k;
        }
    } else if (n % 3 == 2) {
        if (k <= n / 3) {
            ans2 = 2 * k;
        } else if (k == n / 3 + 1) {
            ans2 = n / 3 * 2 + 1;
        } else if (k > n / 3 + 1) {
            ans2 = n - k;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
