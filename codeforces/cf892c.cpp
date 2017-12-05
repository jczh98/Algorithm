#include <bits/stdc++.h>
using namespace std;
int n, a[2005], ans, cnt_1 = 0;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if(a[i] == 1) cnt_1++;
    }
    ans = a[1];
    for(int i = 2; i <= n; ++i) ans = __gcd(ans, a[i]);
    if(ans != 1 || (n == 1 && !cnt_1)) {cout << -1 << endl; return 0;}
    if(n == 1 && cnt_1) {cout << 0 << endl;return 0;}
    if(cnt_1) {cout << n - cnt_1 << endl; return 0;}
    ans = 0x7f7f7f7f;
    for(int i = 1; i <= n; ++i) {
        int L, R, gl = a[i], gr;
        for(L = i + 1; L <= n; ++L) {
            gl = __gcd(gl, a[L]);
            if(gl == 1) break;
        }
        gr = a[L];
        for(R = L - 1; R >= 1; R--) {
            gr = __gcd(gr, a[R]);
            if(gr == 1) break;
        }     
        ans = min(L - R, ans);   
    }
    cout << ans + n - 1 << endl;
    return 0;
}