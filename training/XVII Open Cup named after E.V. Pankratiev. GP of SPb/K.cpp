#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> ans = {2, 3, 5, 7, 23, 37, 53, 73, 373};
int main() {
    freopen("ultraprime.in", "r", stdin);
    freopen("ultraprime.out", "w", stdout);
    cin >> n;
    if(n > 9) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans[n - 1] << endl;
    return 0;
}

