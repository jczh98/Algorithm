#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t, n;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", 2 * (int)ceil(sqrt(1LL * 12 * n - 3)));
    }
    return 0;
}