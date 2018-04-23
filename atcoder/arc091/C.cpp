#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, m, ans = 0;
int main() {
    cin >> n >> m;
    if(n == 1 && m == 1) {
        cout << 1 << endl; return 0;
    }
    if(n == 1 || m == 1) {
        cout << max(n, m) - 2 << endl; return 0;
    }
    ans = (n - 2) * (m - 2);
    cout << ans << endl;
    return 0;
}