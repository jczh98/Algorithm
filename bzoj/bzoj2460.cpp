#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node {
    LL x;
    int val;
    bool operator < (const node & rhs) const {return val > rhs.val;}
}a[1005];
int n, ans = 0;
LL b[65];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%lld%d", &a[i].x, &a[i].val);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i) {
        for(LL j = 63; j >= 0; --j) {
            if((a[i].x >> j) & 1) {
                if(b[j]) a[i].x ^= b[j];
                else {
                    b[j] = a[i].x; ans += a[i].val; break;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}