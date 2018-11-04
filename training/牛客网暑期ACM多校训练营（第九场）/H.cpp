#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long ll;
const int N = 100005, MOD = 1000000007, LEN = 2000;
ll C[N];
ll pre[N], now[N];
pair<ll,ll> Q[LEN + 5];
int n, m, k, opt;
inline void precalc() {
    C[0]=1;
    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j < n; ++j) {
            C[j] = (C[j-1] + C[j]) % MOD;
        }
    }
}
inline void rebuild() {
    memset(pre, 0, sizeof(pre));
    for(int i = 0; i < LEN; ++i) {
        if(Q[i].first == inf) continue;
        pre[Q[i].first] += Q[i].second; pre[Q[i].first] %= MOD;
    }
    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j <= n; ++j) {
            pre[j] = (pre[j-1] + pre[j]) % MOD;
        }
    }
    for(int i = 1; i <= n; ++i) {
        now[i] = (now[i] + pre[i]) % MOD;
    }
}
int main() {
    scanf("%d%d%d", &n, &m, &k);
    precalc();
    for(int i = 0; i < m; ++i) {
        scanf("%d", &opt);
        if(opt == 0) {
            int x, y;
            scanf("%d%d", &x, &y);
            Q[i%LEN].first = x; Q[i%LEN].second = y;
        } else {
            int x;
            scanf("%d", &x);
            Q[i%LEN].first = inf;
            ll ans = now[x];
            for(int j = 0; j < i%LEN; ++j) {
                if(Q[j].first > x) continue;
                int modi = Q[j].first;
                ans = (ans + C[x-modi] * Q[j].second % MOD) % MOD;
            }
            printf("%lld\n", ans);
        }
        if(i%LEN == LEN-1) rebuild();
    }
    return 0;
}