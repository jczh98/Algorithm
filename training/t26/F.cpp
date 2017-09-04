#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL > pLL;
const LL MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
int n, a[1000], vis[1000], i, j, k;
set<pLL> st;
LL QuickPow(LL a, LL b, LL MOD) {
    LL res = 1;
    while(b) {
        if(b & 1) res = (res + a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
int main() {
    freopen("numbereater.in", "r", stdin);
    freopen("numbereater.out", "w", stdout);
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    LL sum1, sum2;
    for(i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        sum1 = 0; sum2 = 0;
        for(j = i; j <= n; j++) {
            if(!vis[a[j]]) {
                sum1 = (sum1 + QuickPow(a[j], a[j], MOD1)) % MOD1;
                sum2 = (sum2 + QuickPow(a[j], a[j], MOD2)) % MOD2;
                vis[a[j]] = 1;
                st.insert(make_pair(sum1, sum2));
            }
        }
    }
    printf("%d\n", st.size());
    return 0;
}

