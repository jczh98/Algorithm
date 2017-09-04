#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;
int n, k, m, f[MAXN];
int main() {
    freopen("A.in", "r", stdin);
    while(scanf("%d%d%d", &n, &k, &m) != EOF) {
        if(n == 0 && k == 0 && m == 0) break;
        f[1] = 0;
        for(int i = 2; i <= n; i++) {
            f[i] = (f[i - 1] + k) % i;
        }
        printf("%d\n", ((m - k + f[n]) % n + n) % n + 1);
    }
    return 0;
}

