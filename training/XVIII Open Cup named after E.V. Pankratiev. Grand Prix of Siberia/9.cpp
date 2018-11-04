#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000000;
bool check[N];
int prime[N], tot, c[N];
void sieve() {
    memset(check, 0, sizeof(check));
    tot = 0;
    for(int i = 2; i < N; ++i) {
        if(!check[i]) {
            prime[tot++] = i; c[i] = i;
        }
        for(int j = 0; j < tot; ++j) {
            if(1LL * i * prime[j] >= N) break;
            check[i * prime[j]] = true;
            c[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) {
                 break;
            }
        }
    }
}
int q, n;
int qpow(int a, int b, int mod) {
    int ret = 1;
    while(b) {
        if(b & 1) ret = (1LL * ret * a) % mod;
        a = (1LL * a * a) % mod; b >>= 1;
    }
    return ret; 
}
// int fac[1000], cnt;
// inline void precalc(int x) {
//     for(int i = 2; i * i <= x; ++i) {
//         if(x % i == 0) {
//             fac[cnt++] = i;
//             while(x % i == 0) x /= i;
//         }
//     }
//     if(x - 1) fac[cnt++] = x;
// }

inline bool calc(int p) {
    if(qpow(q, n, p) != 1) return false;
    if(p - 1 < n) return false;
    //memset(fac, 0, sizeof(fac)); cnt = 0;
    //precalc(p - 1);
    int k = p - 1, t = p - 1;
    while(t > 1) {
        //cout << k << " " << c[k] << endl;
        if(qpow(q, k / c[t], p) == 1) k /= c[t];
        if(n > k) return false;
        t /= c[t];
    }
    return true;
}
int ans[1000005], ans_cnt = 0;
int main() {
    sieve();
    scanf("%d%d", &q, &n);
    for(int i = 0; i < tot; ++i) {
        if(calc(prime[i])) ans[ans_cnt++] = prime[i];
    }
    printf("%d\n", ans_cnt);
    for(int i = 0; i < ans_cnt; ++i) {
        printf("%d%c", ans[i], i == ans_cnt - 1 ? '\n' : ' ');
    }
    return 0;
}