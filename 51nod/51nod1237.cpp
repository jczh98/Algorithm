#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 4641588;
const LL MOD = 1e9 + 7, Inv = 500000004;
LL phi[MAXN + 10], prime[MAXN + 10], tot;
bool check[MAXN + 10];
void Shaker() {
    memset(check, 0, sizeof(check));
    phi[1] = 1; tot = 0;
    for(LL i = 2; i <= MAXN; ++i) {
        if(!check[i]) prime[tot++] = i, phi[i] = i - 1;
        for(LL j = 0; j < tot; ++j) {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = 1;
            if(i % prime[j] == 0) {phi[i * prime[j]] = phi[i] * prime[j]; break;}
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    for(LL i = 2; i <= MAXN; ++i) phi[i] = (phi[i] + phi[i - 1]) % MOD;
}
unordered_map<LL, LL> Hash;
LL CalPhi(LL n) {
    if(n <= MAXN) return phi[n];
    if(Hash[n]) return Hash[n];
    LL res = ((n % MOD * (n % MOD + 1) % MOD) % MOD * Inv % MOD) % MOD, r, tmp = 0;
    for(LL i = 2; i <= n; i = r + 1) {
        r = n / (n / i);
        tmp = (tmp + ((r - i + 1) % MOD * CalPhi(n / i) % MOD) % MOD) % MOD;
    }
    res = (res - tmp + MOD) % MOD;
    return Hash[n] = res;
}
LL Solve(LL n) {
    LL res = 0, r = 0;
    for(LL i = 1; i <= n; i = r + 1) {
        r = n / (n / i);
        res = (res + (((n / i) % MOD) * ((n / i) % MOD) % MOD * (CalPhi(r)  - CalPhi(i - 1) + MOD) % MOD) % MOD) % MOD;
    }
    return res;
}
LL x;
int main() {
    Shaker();
    cin >> x;
    cout << Solve(x) << endl;
    return 0;
}

