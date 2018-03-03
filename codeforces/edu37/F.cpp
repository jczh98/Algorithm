#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300005;
const int M = 1000005;
int a[N];
int lch[N << 2], rch[N << 2];
LL sum[N << 2], Max[N << 2];
LL prime[M], e[M], d[M];
int check[M], cnt;
void seive() {
    memset(check, 0, sizeof(check)); cnt = 0; d[1] = 1; e[1] = 1;
    for(int i = 2; i < M; ++i) {
        if(!check[i]) {prime[cnt++] = i; e[i] = 1; d[i] = 2;}
        for(int j = 0; j < cnt; ++j) {
            if(1LL * i * prime[j] >= M) break;
            check[i * prime[j]] = 1;
            if(i % prime[j] == 0) {
                e[i * prime[j]] = e[i] + 1;
                d[i * prime[j]] = d[i] / (e[i] + 1) * (e[i] + 2);
                break;
            }else {
                d[i * prime[j]] = d[i] * 2; e[i * prime[j]] = 1;
            }
        }
    }
}
inline void pushup(int x) {
    sum[x] = sum[x << 1] + sum[x << 1 | 1];
    Max[x] = max(Max[x << 1], Max[x << 1 | 1]);
}
void build(int x, int l, int r) {
    lch[x] = l; rch[x] = r; sum[x] = Max[x] = 0;
    if(l == r) {
        sum[x] = Max[x] = a[l]; return;
    }
    int mid = (l + r) / 2;
    build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
    pushup(x);
}
void update(int x, int l, int r) {
    if(Max[x] <= 2) return;
    if(lch[x] == rch[x]) {
        sum[x] = Max[x] = d[sum[x]]; return;
    }
    int mid = (lch[x] + rch[x]) / 2;
    if(r <= mid) update(x << 1, l, r);
    else if(l > mid) update(x << 1 | 1, l, r);
    else update(x << 1, l, mid), update(x << 1 | 1, mid + 1, r);
    pushup(x);
}
LL query(int x, int l, int r) {
    if(l == lch[x] && rch[x] == r) return sum[x];
    int mid = (lch[x] + rch[x]) / 2;
    if(r <= mid) return query(x << 1, l, r);
    else if(l > mid) return query(x << 1 | 1, l, r);
    else return query(x << 1, l, mid) + query(x << 1 | 1, mid + 1, r);
}
int n, m, t, l, r;
int main() {
    seive();
    // for (int i = 1; i < M; i++)
    //     for (int j = i; j < M; j += i) d[j]++;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    build(1, 1, n);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &t, &l, &r);
        if(t == 1) update(1, l, r);
        else printf("%I64d\n", query(1, l, r));
    }
    return 0;
}