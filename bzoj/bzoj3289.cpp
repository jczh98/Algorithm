#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50010;
struct Node{
    int l, r, id;
}query[MAXN];
int n, q, a[MAXN], b[MAXN], block, pos[MAXN], c[MAXN], tot = 0, ans = 0, data[MAXN];
inline void Update(int x, int v) {
    for(; x <= n; x += (x & (-x))) {
        c[x] += v;
    }
}
inline int Query(int x) {
    int ret = 0;
    for(; x > 0; x -= (x & (-x))) {
        ret += c[x];
    }
    return ret;
}
bool cmp(Node a, Node b) {
    if(pos[a.l] == pos[b.l]) return a.r < b.r;
    else return pos[a.l] < pos[b.l];
}
int main() {
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    tot = unique(b + 1, b + 1 + n) - b - 1;
    for(int i = 1; i <= n; ++i) a[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
    block = sqrt(n * 1.0);
    for(int i = 1; i <= n; ++i) pos[i] = (i - 1) / block + 1;
    scanf("%d", &q);
    for(int i = 1; i <= q; ++i) scanf("%d%d", &query[i].l, &query[i].r), query[i].id = i;
    sort(query + 1, query + q + 1, cmp);
    int L = 1, R = 0; ans = 0;
    for(int i = 1; i <= q; ++i) {
        if(query[i].l == query[i].r) {data[i] == 0; continue;}
        while(R < query[i].r) {
            ++R;
            ans += R - L - Query(a[R]); Update(a[R], 1);
        }
        while(R > query[i].r) {
            ans -= R - L + 1 - Query(a[R]); Update(a[R], -1);
            --R;
        }
        while(L < query[i].l) {
            ans -= Query(a[L] - 1); Update(a[L], -1);
            ++L;
        }
        while(L > query[i].l) {
            --L;
            ans += Query(a[L] - 1); Update(a[L], 1);
        }
        data[query[i].id] = ans;
    }
    for(int i = 1; i <= q; ++i) {
        printf("%d\n", data[i]);
    }
    return 0;
}