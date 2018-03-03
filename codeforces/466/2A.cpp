#include <bits/stdc++.h>
using namespace std;
int n, d;
int a[1000], ans = 0;
int main() {
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++i) {
        for(int j = i; j <= n; ++j) {
            if(a[j] - a[i] <= d) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    printf("%d\n", n - ans);
    return 0;
}