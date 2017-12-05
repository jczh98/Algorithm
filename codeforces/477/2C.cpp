#include <bits/stdc++.h>
using namespace std;
int n, a[10005],g;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    g = a[1];
    for(int i = 2; i <= n; ++i) g = __gcd(g, a[i]);
    if(g != a[1]) {printf("-1\n"); return 0;}
    cout << 2 * n << endl;
    for(int i = 1; i <= n; ++i) {
        printf("%d %d%c", a[i], g, i == n ? '\n' : ' ');
    }
    return 0;
}