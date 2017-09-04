#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL > pLL;
int a[10];
LL seed = 23, MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
pLL getHash(int *b) {
    LL sum1 = seed, sum2 = seed;
    for(int i = 1; i <= 6; i++) {
        sum1 = (sum1 * seed + b[i]) % MOD1;
        sum2 = (sum2 * seed + b[i]) % MOD2;
    }
    return make_pair(sum1, sum2);
}
char t[10];
int main() {
    a[6] = 15;
    while(scanf("%s", &t) != EOF) {
        if(t[0] == 'e') break;
    }
}
