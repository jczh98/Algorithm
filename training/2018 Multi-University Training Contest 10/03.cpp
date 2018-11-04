#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1LL<<30;
const int N = 10000000;
int prime[N+5], low[N+5], check[N+5], pow_cnt[N+5], tot, f[N+5], f2[N+5], f3[N+5];
void sieve() {
    memset(check, 0, sizeof(check));
    low[1] = 1; tot = 0; f[1] = f2[1] = f3[1] = 1; pow_cnt[1] = 0; 
    for(int i = 2; i <= N; ++i) {
        if(!check[i]) {
            low[i] = i; prime[tot++] = i;f[i] = i-2;
            f2[i] = i; f3[i] = i; pow_cnt[i] = 1;
        }
        for(int j = 0; j < tot; ++j) {
            if(i * prime[j] > N) break;
            check[i*prime[j]] = 1;
            if(i % prime[j] == 0) {
                pow_cnt[i * prime[j]] = pow_cnt[i] + 1;
                low[i * prime[j]] = low[i] * prime[j];             
                if(low[i] == i) {
                    if(i == prime[j]) f[i * prime[j]] = prime[j]*prime[j]+1-2*prime[j];
                    else f[i * prime[j]] = f[i] * prime[j];
                    f2[i * prime[j]] = f2[i];
                    f3[i * prime[j]] = f3[i];
                    if(pow_cnt[i*prime[j]] % 2 == 1) f2[i * prime[j]] *= prime[j];
                    if(pow_cnt[i*prime[j]] % 3 == 1) f3[i * prime[j]] *= prime[j];
                }else {
                    f[i * prime[j]] = f[i / low[i]] * f[low[i] * prime[j]];
                    f2[i * prime[j]] = f2[i / low[i]] * f2[low[i] * prime[j]];
                    f3[i * prime[j]] = f3[i / low[i]] * f3[low[i] * prime[j]];
                }
                break;
            }else {
                low[i * prime[j]] = prime[j];
                pow_cnt[i * prime[j]] = 1;
                f[i * prime[j]] = f[i] * f[prime[j]];
                f2[i * prime[j]] = f2[i] * f2[prime[j]];
                f3[i * prime[j]] = f3[i] * f3[prime[j]];
            }
        }
    }
}
int t, A, B, C;
int main() {
    sieve();
    // for(int i = 1; i <= 100; ++i) {
    //     cout << f3[i] << " ";
    // }cout << endl;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &A, &B, &C);
        ll ans = 0;
        for(int i = 1; i <= max(A,max(B,C)); ++i) {
            ans = (ans + (A/i)*(B/f2[i])%mod*(C/f3[i])%mod*f[i]%mod)%mod;
        }
        cout << ans << endl;
    }
}