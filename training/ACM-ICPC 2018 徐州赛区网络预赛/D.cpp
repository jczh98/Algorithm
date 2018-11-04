#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 20000000;
bool check[N+20];
int prime[N+20], mu[N+20], tot;
void mobius() {
    memset(check, 0, sizeof(check));
    mu[1] = 1; tot = 0;
    for(int i = 2; i <= N; ++i) {
        if(!check[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for(int j = 0; j < tot; ++j) {
            if(i * prime[j] > N) break;
            check[i * prime[j]] = true;
            if(i % prime[j] == 0) {
                mu[i * prime[j]] = 0; break;
            }else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    for(int i = 2; i <= N; ++i) mu[i] += mu[i-1];
}
ll factor[50]; int f_cnt = 0, f_exp[50];
void get_factor(ll x) {
    f_cnt = 0; ll n = x;
    for(int i = 0; i < tot; ++i) {
        if(1LL * prime[i] * prime[i] > n) break;
        if(x % prime[i] == 0) {
            f_exp[f_cnt] = 0;
            while(x % prime[i] == 0) {
                x /= prime[i]; f_exp[f_cnt]++;
            }
            factor[f_cnt++] = prime[i];
        }
    }
    if(x > 1) {
        f_exp[f_cnt] = 1; factor[f_cnt++] = x;
    }
}
map<ll, int> mp;
ll mertens(ll x) {
    if(x < N) return mu[x];
    if(mp.count(x)) return mp[x];
    ll ret = 0;
    for(ll i = 2, last; i <= x; i = last+1) {
        last = x/(x/i);
        ret += (last - i + 1)*mertens(x/i);
    }
    return mp[x] = 1-ret;
}
ll S(ll n, ll m, ll min_p) {
    if(m == 0) return 0;
    if(n == 1) return mertens(m);
    ll p = factor[min_p];
    //cout << n << " " << m << " " << p << endl;
    return -S(n/p,m,min_p+1)+S(n,m/p,min_p);
}
ll m, n;
int main() {
    mobius();
    cin >> m >> n;
    get_factor(n);
    for(int i = 0; i < f_cnt; ++i) {
        if(f_exp[i] > 1) {
            puts("0"); return 0;
        }
    }
    cout << S(n, m, 0) << endl;
    return 0;
}