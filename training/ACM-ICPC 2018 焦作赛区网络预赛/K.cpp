#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int t, n, q, v[30], c[30], s;
ll dp[10005];
vector<int> vec;
int main() {
    scanf("%d", &t);
    while(t--){
        vec.clear();
        scanf("%d%d", &n, &q);
        for(register int i = 1; i <= n; ++i) scanf("%d%d", &v[i], &c[i]);
        for(register int i = 1; i <= n; ++i) {
            int w = (1<<c[i])-1;
            for(register int j = 1; j <= w; j<<=1) {
                vec.push_back(j*v[i]); w-=j;
            }
            if(w>0)vec.push_back(w*v[i]);
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(register int i = 0; i < vec.size(); ++i) {
            for(register int j = 10000; j >= vec[i]; --j) {
                dp[j] = (dp[j-vec[i]] + dp[j]) % MOD;
            }
        }
        for(register int K = 1; K <= q; ++K) {
            scanf("%d", &s);
            printf("%lld\n", dp[s]);
        }
    }
    return 0;
}