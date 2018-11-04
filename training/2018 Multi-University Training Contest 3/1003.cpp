#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int t, n, m;
char op[10];
int u, v;
ll f[1024], ans[10];
int calc(int x) {
    int ret = 0;
    while(x) x&=(x-1), ret++;
    return ret;
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        f[0] = 1;
        for(register int i = 1; i <= m; ++i) {
            scanf("%s%d%d", op, &u, &v); u--, v--;
            if(op[0] == '+') for(register int S = (1 << n) - 1; S >= 0; --S) {
                if((S & (1 << u)) && (S & (1 << v))) {
                    int last = S ^ (1 << u) ^ (1 << v);
                    f[S] = (f[S] + f[last]) % mod;
                }
            }
            if(op[0] == '-') for(register int S = (1 << n) - 1; S >= 0; --S) {
                if(!(S & (1 << u)) && !(S & (1 << v))) {
                    int last = S ^ (1 << u) ^ (1 << v);
                    f[S] = (f[S] - f[last] + mod) % mod;
                }
            }
            for(int S = 0; S < (1 << n); ++S) {
                int p = calc(S);
                if(p & 1) continue;
                ans[p / 2] = (ans[p / 2] + f[S]) % mod;
            }
            for(register int j = 1; j <= n / 2; ++j) {
                printf("%lld%c", ans[j], j == n / 2 ? '\n' : ' ');
            }
        }
    }
    return 0;
}