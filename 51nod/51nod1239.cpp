#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7, Inv = 500000004;
const LL MAXN = 4641599;
LL phi[MAXN + 10], prime[MAXN + 10], tot;
bool check[MAXN + 10];
void Shaker() {
    memset(check, 0, sizeof(check));
    phi[1] = 1; tot = 0;
    for(LL i = 2; i <= MAXN; ++i) {
        if(!check[i]) prime[tot++] = i, phi[i] = i - 1;
        for(int j = 0; j < tot; ++j) {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = 1;
            if(i % prime[j] == 0) {phi[i * prime[j]] = phi[i] * prime[j]; break;}
            else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    for(int i = 2; i <= MAXN; ++i) phi[i] = (phi[i] + phi[i - 1]) % MOD;
}
unordered_map<LL, LL> Hash;
LL Cal(LL n) {
    if(n <= MAXN) return phi[n];
    if(Hash[n]) return Hash[n];
    LL res = ((n % MOD * (n % MOD + 1) % MOD) % MOD * Inv % MOD) % MOD, r, tmp = 0;
    for(LL i = 2; i <= n; i = r + 1) {
        r = n / (n / i);
        tmp = (tmp + ((r - i + 1) % MOD * Cal(n / i) % MOD) % MOD) % MOD;
    }
    res = (res - tmp + MOD * 2) % MOD;
    return Hash[n] = res;
}
LL n;
int main() {
    Shaker();
    cin >> n;
    cout << Cal(n) << endl;
    return 0;
}

