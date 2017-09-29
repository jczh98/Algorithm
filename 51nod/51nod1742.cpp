#include <bits/stdc++.h>
#define M 44723
using namespace std;
typedef long long LL;
int mu[M] = {0, 1}, prime[M], tot;
bool not_prime[M];
void Linear_Shaker() {
    for (int i = 2; i < M; ++i) {
        if (!not_prime[i])
            mu[i] = -1, prime[++tot] = i;
        for (int j = 1; prime[j] * i < M; ++j) {
            not_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                mu[prime[j] * i] = 0;
                break;
            }
            mu[prime[j] * i] = -mu[i];
        }
    }
}
LL Cal(LL x) {
    LL res = x;
    for(int i = 1; i * i <= x; ++i) {
        res -= x / (i * i) * mu[i];
    }
    return res;
}
LL S(LL x) {
    LL res = 0, cnt = 1;
    for(int i = 1; i < x && cnt; i += cnt) {
        cnt = x / (x / i) - x / ((x / i) + 1);
        res += cnt * Cal(x / i);
    }
    return res;
}
LL a, b;
int main() {
    Linear_Shaker();
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", S(b) - S(a - 1));
    return 0;
}