#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 4641588, MOD = 1e9 + 7, Inv2 = 500000004, Inv6 = 166666668;
LL phi[MAXN + 10], prime[MAXN + 10], sum[MAXN + 10], tot;
bool check[MAXN + 10];
inline void Shaker() {
    LL i, j; phi[1] = 1; tot = 0; sum[1] = 1;
    for(i = 2; i <= MAXN; ++i) {
        if(!check[i]) prime[tot++] = i, phi[i] = i - 1;
        for(j = 0; j < tot; ++j) {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = 1;
            if(i % prime[j] == 0) {phi[i * prime[j]] = phi[i] * prime[j]; break;}
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    sum[1] = 1;
    for(i = 2; i <= MAXN; ++i) sum[i] = (sum[i - 1] + (phi[i]%MOD * i%MOD * i%MOD)%MOD) % MOD;
}
inline LL CalId2(LL n) {n %= MOD; return n * (n + 1)%MOD * (2 * n%MOD + 1)%MOD * Inv6%MOD;}
inline LL CalId1(LL n) {n %= MOD; return n * (n + 1)%MOD * Inv2%MOD;}
inline LL CalId3(LL n) {LL ret = CalId1(n); return ret * ret%MOD;}
inline LL Sum1(LL l, LL r) {return (CalId1(r) - CalId1(l) + MOD )% MOD; }
inline LL Sum2(LL l, LL r) {return (CalId2(r) - CalId2(l) + MOD )% MOD; }
inline LL Sum3(LL l, LL r) {return (CalId3(r) - CalId3(l) + MOD )% MOD; }
unordered_map<LL, LL> Hash;
LL CalPreSum(LL n) {
    if(n <= MAXN) return sum[n];
    if(Hash[n]) return Hash[n];
    LL ret = CalId3(n);
    for(LL i = 2, r; i <= n; i = r + 1) {
        r = n / (n / i);
        ret = (ret - Sum2(i - 1, r) * CalPreSum(n / i)%MOD) % MOD;
    }
    return Hash[n] = ret;
}
inline LL Solve(LL n) {
    LL ret = 0;
    for(LL i = 1, r; i <= n; i = r + 1) {
        r = n / (n / i);
        ret = (ret + Sum1(i - 1, r) * CalPreSum(n / i)%MOD)%MOD;
    }
    return ret;
}
LL x;
int main() {
    ios::sync_with_stdio(false);
    Shaker();
    cin >> x;
    cout << Solve(x) << endl;
    return 0;
}