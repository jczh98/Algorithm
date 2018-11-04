#include <bits/stdc++.h>
using namespace std;
const int N = 20000000;
int prime[2000000], low[N+5], tot, f[N+5];
bool check[N+5];
void sieve() {
    memset(check, 0, sizeof(check));
    low[1] = 1; tot = 0; f[1] = 1; 
    for(int i = 2; i <= N; ++i) {
        if(!check[i]) {
            low[i] = i; prime[tot++] = i;f[i] = 2;
        }
        for(int j = 0; j < tot; ++j) {
            if(i * prime[j] > N) break;
            check[i*prime[j]] = true;
            if(i % prime[j] == 0) {
                low[i * prime[j]] = low[i] * prime[j];             
                if(low[i] == i) {
                    if(i==prime[j]) f[i*prime[j]] = 1;
                    else f[i*prime[j]] = 0;
                }else {
                    f[i * prime[j]] = f[i / low[i]] * f[low[i] * prime[j]];
                }
                break;
            }else {
                low[i * prime[j]] = prime[j];
                f[i * prime[j]] = f[i] * f[prime[j]];
            }
        }
    }
}
int sum[N+5], n;
int t;
int main() {
    sieve();
    for(int i = 1; i <= N; ++i) {
        sum[i] = sum[i-1] + 1LL * f[i];
    }
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", sum[n]);
    }
    return 0;
    // for(int i = 1; i <= 100; ++i) {
    //     cout << f[i] << " ";
    // }cout << endl;
}