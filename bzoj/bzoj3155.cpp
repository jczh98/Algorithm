#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, q, a[100005], t, val;
char query[100];
struct Fenwick{
    LL C[100005];
    int N;
    void Init(LL x) {
        this->N = x;
    }
    LL Lowbit(LL x) {
        return x & (-x);
    }
    void Add(LL x, LL v) {
        while(x <= N) {
            C[x] += v;
            x += Lowbit(x);
        }
    }
    LL Sum(LL x) {
        LL res = 0;
        while(x) {
            res += C[x];
            x -= Lowbit(x);
        }
        return res;
    }
}pre1, pre2;
int main() {
    scanf("%lld%lld", &n, &q);
    pre1.Init(n);
    pre2.Init(n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        pre1.Add(i, a[i]);
        pre2.Add(i, i * a[i]);
    }
    for(int i = 1; i <= q; i++) {
        scanf("%s", query);
        if(query[0] == 'Q') {
            scanf("%lld", &t);
            printf("%lld\n", (t + 1) * pre1.Sum(t) - pre2.Sum(t));
        }
        if(query[0] == 'M') {
            scanf("%lld%lld", &t, &val);
            pre1.Add(t, val - a[t]);
            pre2.Add(t, t * (val - a[t]));
            a[t] = val;
        }
    }
    return 0;
}

