#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MAXN = 1664510;
LL mu[MAXN + 10], phi[MAXN + 10], prime[MAXN + 10], tot;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x)
{if(x<0)putchar('-'),x=-x;if(x>=10)print(x/10);putchar(x%10+'0');}

bool check[MAXN + 10];
void Shaker() {
    memset(check, 0, sizeof(check));
    mu[1] = 1; phi[1] = 1; tot = 0;
    for(register int i = 2; i <= MAXN; ++i) {
        if(!check[i]) prime[tot++] = i, mu[i] = -1, phi[i] = i - 1;
        for(register int j = 0; j < tot; ++j) {
            if(i * prime[j] > MAXN) break;
            check[i * prime[j]] = 1;
            if(i % prime[j] == 0) {mu[i * prime[j]] = 0; phi[i * prime[j]] = phi[i] * prime[j]; break;}
            else mu[i * prime[j]] = -mu[i], phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
    for(register int i = 2; i <= MAXN; ++i) mu[i] += mu[i - 1], phi[i] += phi[i - 1];
}
map<LL, LL> Hash1;
LL Cal1(LL n) {
    if(n <= MAXN) return mu[n];
    if(Hash1[n]) return Hash1[n];
    register LL r = 0, res = 1;
    for(register LL i = 2; i <= n; i = r + 1) {
        r = n / (n / i);
        res -= (r - i + 1) * Cal1(n / i);
        if(r == n) break;
    }
    return Hash1[n] = res;
}
map<LL, LL> Hash2;
LL Cal2(LL n) {
    if(n <= MAXN) return phi[n];
    if(Hash2[n]) return Hash2[n];
    register LL res = (n * (n + 1)) >> 1 , r;
    for(register LL i = 2; i <= n; i = r + 1) {
        r = n / (n / i);
        res -= (r - i + 1) * Cal2(n / i);
        if(r == n) break;
    }
    return Hash2[n] = res;
}
int main() {
    register LL T, x;
    Shaker();
    T = read();
    for(; T; --T) {
        x = read();
        print(Cal2(x)); putchar(' '); print(Cal1(x)); puts("");
    }
    return 0;
}

