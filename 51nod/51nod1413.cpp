#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
    cin >> n;
    for(; n; n /= 10) {
        ans = max(ans, n % 10);
    }
    cout << ans << endl;
    return 0;
}

