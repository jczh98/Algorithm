#include <bits/stdc++.h>
using namespace std;
int l[1000005], ans = 1, n, k;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &l[i]);
    k = n;
    for(int i = n; i >= 1; --i) {
        if(k > i) ans++;
        k = min(k, i - l[i]);
    }
    cout << ans << endl;
    return 0;
}