#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128_t int128;
const int N = 100000;
bool check[N+5];
int prime[N+5], mu[N+5], tot;
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
}
ll n, p;
int128 qpow(int128 a, int128 b, int128 mod) {
    int128 ret = 1;
    while(b) {
        if(b & 1) ret = (ret * a) % mod;
        a = (a * a) % mod; b >>= 1;
    }
    return ret;
}
int128 sum2(int128 x) {
    int128 ret = x;
    ret = ret*(1+x)*(1+2*x)/6;
    return ret%p;
}
int128 sum3(int128 x) {
    int128 ret = x;
    ret = ret * (1+x)/2;
    return ret%p*ret%p;
}
int main() {
    mobius();
    while(cin >> n >> p) {
        int128 N = n, P = p, ans = 0;
        for(ll i = 1; i * i <= n; ++i) {
            int128 mul = (N+1)*qpow(i,4,P)%P;
            mul = mul * sum2(N/(i*i))%P;
            int128 mul2 = qpow(i,6,P);
            mul2 = mul2 * sum3(N/(i*i))%P;
            ans = (ans + (mul-mul2+P)*mu[i]%P+P)%P;
        }  
        ll Ans = ans;
        cout << Ans << endl;     
    }
    return 0;
}