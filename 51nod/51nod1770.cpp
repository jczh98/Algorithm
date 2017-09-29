#include <bits/stdc++.h>
using namespace std;
int a, b, n, t, d, ans[10];
int main() {
    cin >> t;
    for(; t; t--) {
        memset(ans, 0, sizeof(ans));
        cin >> a >> b >> d >> n;
        if(a * b < 10) {
            if(d == a * b) cout << n << endl; else cout << 0 << endl;
        }else {
            int t = a * b; a = t / 10; b = t % 10;
            if(n == 1) {
                if(d == a || d == b) cout << 1 << endl; else cout << 0 << endl;
                continue;
            }
            ans[a]++; ans[b]++;
            if(a + b < 10) {
                ans[a + b] += n - 1;
            }else {
                ans[(a + b) % 10]++;
                ans[(a + b) % 10 + 1] += n - 2;
                ans[a]--; ans[a + 1]++;
            }
            if(ans[d]) cout << ans[d] << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}

