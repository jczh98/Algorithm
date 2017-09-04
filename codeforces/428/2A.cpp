#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000], ans, rem = 0;
int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] + rem >= 8) {
            ans += 8;
            rem = (a[i] + rem - 8);
        }else {
            ans += a[i] + rem;
            rem = 0;
        }
        if(ans >= k) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

