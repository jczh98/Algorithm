#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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
}t[20];
LL n, m, q, a[10005], ans, pos, l ,r, mod, before, after;
char query[1000];
int main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 0; i <= 10; i++) {
        t[i].Init(n);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        t[a[i] % m].Add(i, a[i]);
    }
    scanf("%lld", &q);
    for(int i = 1; i <= q; i++) {
        scanf("%s", query);
        if(query[0] == 's') {
            scanf("%lld%lld%lld", &l, &r, &mod);
            ans = t[mod].Sum(r) - t[mod].Sum(l-1);
            printf("%lld\n", ans);
        }
        if(query[0] == '+') {
            scanf("%lld%lld", &pos, &r);
            before = a[pos];
            after = a[pos] + r;
            t[before % m].Add(pos, -before);
            t[after % m].Add(pos, after);
            a[pos] += r;
            printf("%lld\n", a[pos]);
        }
        if(query[0] == '-') {
            scanf("%lld%lld", &pos, &r);
            before = a[pos];
            after = a[pos] - r;
            if(after >= 0) {
                t[before % m].Add(pos, -before);
                t[after % m].Add(pos, after);
                a[pos] -= r;
            }
            printf("%lld\n", a[pos]);
        }
    }
    return 0;
}

