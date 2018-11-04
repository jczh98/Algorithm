#include <bits/stdc++.h>
#define ff(i, x, y) for(int i = x; i <= y; i++)
#define fs(i, x, y) for(int i = x; i >= y; i--)
using namespace std;
typedef __int128_t ll;
//const ll mod = 1e9 + 7;
ll n, ans[10] = {1, 9, 41, 109, 205, 325, 473, 649, 853, 1085}, d = 260;
int main() {
    int t;
    scanf("%d", &t);
    int cnt = 0;
    while(t--) {
        cnt++;
        printf("Case #%d: ", cnt);
        //scanf("%lld", &n);
        cin >> n;
        if(n <= 9)
            cout << ans[n] << endl;
            //printf("%lld\n", ans[n]);
        else {
            ll tp = d + 28 * (n - 10);
            n -= 9;
            ll res = ans[9] + ((tp + d) / 2) * n;
            //printf("%lld\n", res);
            cout << res << endl;
        }
    }
    return 0;
}
