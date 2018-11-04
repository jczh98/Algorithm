#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10000005;
int t, a[N], n, m, k, p, q, r, mod, que[N], head, tail;
ll A, B;
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d%d%d%d", &n, &m, &k, &p, &q, &r, &mod);
        for(register int i = 1; i <= k; ++i) {
            scanf("%d", &a[i]);
        }
        for(register int i = k + 1; i <= n; ++i) {
            a[i] = (1LL * a[i - 1] * p % mod + 1LL * q * i % mod + r) % mod;
        }
        head = 1; tail = 0; A = B = 0;
        for(register int i = n; i > n - m + 1; --i) {
            while(head <= tail && a[que[tail]] <= a[i]) tail--;
            que[++tail]=i;
        }
        for(register int i = n - m + 1; i >= 1 ; --i) {
            while(head <= tail && que[head] - i + 1> m) head++;
            while(head <= tail && a[que[tail]] <= a[i]) tail--;
            que[++tail] = i;
            A += a[que[head]] ^ i;
            B += (tail - head + 1) ^ i;
        }
        printf("%lld %lld\n", A, B);
    }
    return 0;
}