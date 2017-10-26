#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a, b, ans = 1;
int main() {
    cin >> a >> b;
    if(a == b) {cout << 1 << endl; return 0;}
    for(LL i = a + 1; i <= b; ++i) {
        ans *= i; ans %= 10;
        if(ans == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}

