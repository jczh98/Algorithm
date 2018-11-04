#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[200005], b[200005], ans;
bool cmp(int x, int y) {
    return x > y;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        ans = 0;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &b[i]);
        }
        sort(a+1, a+1+n);
        sort(b+1, b+1+n, cmp);
        for(int i = 1; i <= n; ++i) {
            if(a[i]+b[i]>=k) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}