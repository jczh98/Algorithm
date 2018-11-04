#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t, n, a[1000], sum;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n); sum = 0;
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]); sum += a[i];
        }
        double ans = sum / n;
        printf("%d\n", int(ans));
    }
    return 0;
}