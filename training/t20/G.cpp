#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n;
LL ans;
int main() {
    freopen("perechi3.in", "r", stdin);
    freopen("perechi3.out", "w", stdout);
    scanf("%d",&t);
    while(t--) {
        ans = 0;
        scanf("%d",&n);
        int len = sqrt(n), R;
        for(int i = 1; i <= len; i++) {
            R = n / i;
            if(R > i) ans += (R - i)*2, ans++;
            if(R == i) ans++;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

