#include <bits/stdc++.h>
using namespace std;
int n;
bool check(int x) {
    if(x == 2 || x == 3 || x == 5 || x == 7 || x == 11 || x == 13 || x == 17) return true;
    else return false;
}
int main() {
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(i == j) continue;
            int g = __gcd(i, j);
            if(check(i / g) && check(j / g)) {
                ans++;
                cout << i << " " << j << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}