#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int k, r, tot = 1, wins;
double ans = 0, p = 1.0;
int main() {
    scanf("%d%d", &k, &r);
    tot = (1 << k) - 1; wins = tot - r + 1;
    for(int i = 1; (1 << i) - 1 <= wins; i++) {
        for(int j = wins - ((1 << i) - 1) + 1, z = tot - ((1 << i) - 1) + 1; j <= wins - (1 << (i - 1)) + 1; j++, z++) {
            p *= (j * 1.0 / z);
        }
        ans += p;
    }
    printf("%.5f\n", ans);
    return 0;
}

