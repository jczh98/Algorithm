#include <bits/stdc++.h>
using namespace std;
int n, k, x;
vector<int> a;
map<int, int> mp;
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &x); a.push_back(x);mp[x]++;
    }
    sort(a.begin(), a.end());
    if(k == 0) {
        if(a[0] == 1) {
            cout << -1 << endl;
        }else {
            cout << a[0] - 1 << endl;
        }
        return 0;
    }
    if(k == n) {
        cout << a[n - 1] << endl;
        return 0;
    }
    x = a[k - 1];
    int y = a[k];
    if(mp[x] > 1) {
        if(x == y) {
            cout << -1 << endl;
        }else {
            cout << x << endl;
        }
    }else {
        cout << x << endl;
    }
    return 0;
}
