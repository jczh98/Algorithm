#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int N = 200005;
struct node {
    int x, k, w;
}Q[2 * N];
pair<int, int> v[N][2];
ll finv[N], fac[N], inv[N];
void precalc() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    inv[1] = 1;
    for (int i = 2; i < N; ++i) {
        inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    finv[0] = 1;
    for (int i = 1; i < N; ++i) {
        finv[i] = 1LL * finv[i - 1] * inv[i] % MOD;
    }
}
ll C(int n, int m) { return fac[n] * finv[m] % MOD * finv[n - m] % MOD; }
ll calc(int x, int y, pair<int, int> val) {
    if (val.second < y) return 0;
    return C(val.first - x + val.second - y - 1, val.second - y);
}
int t, n, m, op, l, r, w, q1, q2, k;
ll ans = 0;
int main() {
    precalc();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        k = 1; ans = 0; q1 = 0; q2 = 0;
        while (m--) {
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d%d", &l, &r, &w);
                Q[++q1].x = l; Q[q1].k = k - 1; Q[q1].w = w;
                Q[++q1].x = r + 1; Q[q1].k = k - 1; Q[q1].w = -w;
            }
            if (op == 2) k++;
            if (op == 3) {
                scanf("%d%d", &l, &r);
                v[++q2][0] = make_pair(k + 1, r);
                v[q2][1] = make_pair(k + 1, l - 1);
                ans = 0;
                for (int i = 1; i <= q1; ++i) {
                    ans = (ans + calc(Q[i].k, Q[i].x, v[q2][0]) * Q[i].w % MOD) % MOD;
                    ans = (ans - calc(Q[i].k, Q[i].x, v[q2][1]) * Q[i].w % MOD + MOD) % MOD;
                }
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}
