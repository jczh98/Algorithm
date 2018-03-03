#include <bits/stdc++.h>
using namespace std;
int n;
string ans;
int main() {
    scanf("%d", &n);
    if(n > 36) {
        cout << -1 << endl;
        return 0;
    }
    if(n == 1) {
        cout << 6 << endl;
        return 0;
    }
    while(n >= 2) {
        ans += '8';
        n -= 2;
    }
    if(n & 1) ans += '0';
    cout << ans << endl;
    return 0;
}