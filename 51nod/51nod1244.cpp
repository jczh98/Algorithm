#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 4641599;
LL mu[MAXN + 10], prime[MAXN + 10], tot;
bool check[MAXN + 10];
void Shaker() {
    memset(check, 0, sizeof(check));
    mu[1] = 1; tot = 0;
    for(int i = 2; i < MAXN; ++i) {
        if(!check[i]) prime[tot++] = i, mu[i] = -1;
        for(int j = 0; j < tot; ++j) {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = 1;
            if(i % prime[j] == 0) {mu[i * prime[j]] = 0; break;}
            else mu[i * prime[j]] = -mu[i];
        }
    }
    for(int i = 2; i <= MAXN; ++i) mu[i] += mu[i - 1];
}
unordered_map<LL, LL> Hash;
LL Cal(LL n) {
    if(n <= MAXN) return mu[n];
    if(Hash[n]) return Hash[n];
    LL r = 0, res = 1;
    for(LL i = 2; i <= n; i = r + 1) {
        r = n / (n / i);
        res -= (r - i + 1) * Cal(n / i);
    }
    return Hash[n] = res;
}
LL a, b;
int main() {
    Shaker();
    cin >> a >> b;
    cout << Cal(b) - Cal(a - 1) << endl;
    return 0;
}

