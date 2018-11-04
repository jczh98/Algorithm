#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005, MOD = 998244353;
bool check[N];
int prime[N], phi[N], tot;
void euler() {
    memset(check, 0, sizeof(check));
    phi[1] = 1; tot = 0;
    for(int i = 2; i < N; ++i) {
        if(!check[i]) {
            prime[tot++] = i;
            phi[i] = i-1;
        }
        for(int j = 0; j < tot; ++j) {
            if(i * prime[j] >= N) break;
            check[i * prime[j]] = true;
            if(i % prime[j] == 0) {
                phi[i * prime[j]] = prime[j] * phi[i]; break;
            }else {
                phi[i * prime[j]] = (prime[j]-1) * phi[i];
            }
        }
    }
}
ll qpow(ll a, ll b, ll mod) {
    ll ret = 1;
    while(b) {
        if(b&1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
ll ans[N];
int t, n, m, A[N], a;
int main() {
    euler();
    scanf("%d", &t);
    while(t--) {
        memset(ans, 0, sizeof(ans));
        memset(A, 0, sizeof(A));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", &a); A[a]++;
        }
        for(int i = 1; i < N; ++i) {
            for(int j = i+i; j < N; j+=i) {
                A[i]+=A[j];
            }
        }
        ll ret = 0;
        for(int i = 1; i <= m; ++i) {
            for(int j = i; j <= m; j += i) {
                ans[j] = (ans[j] + 1LL*(qpow(j+1, A[i], MOD)-1LL)*qpow(j,MOD-2,MOD)%MOD*phi[i]%MOD)%MOD;
            }
        }
        for(int i = 1; i <= m; ++i) ret ^= ans[i];
        printf("%lld\n", ret);
    }
    return 0;
}