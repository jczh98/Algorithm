#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
int main() {
    scanf("%d", &n);
    for(; n; n /= 5) {
        ans += n/5;
    }
    printf("%d\n", ans);
    return 0;
}
