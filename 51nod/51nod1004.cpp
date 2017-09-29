#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Mod = 10;
LL QuickPower(LL a, LL b) {
    LL res = 1;
    for(; b; b >>= 1) {
        if(b & 1) res = (res * a) % Mod;
        a = (a * a) % Mod;
    }
    return res;
}
int n;
int main() {
    scanf("%d", &n);
    printf("%lld\n", QuickPower(n, n));
    return 0;
}

