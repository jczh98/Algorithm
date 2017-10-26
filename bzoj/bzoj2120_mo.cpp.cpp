#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const int MAXM = 1000005;
int n, m, a[MAXN], b[MAXN], block, ll, rr, num, cnt, pos[MAXN], c[MAXM];
int L = 1, R = 0, now = 0, ans = 0, data[MAXN];
char ss[10];
struct Node {
    int l, r, x, id;
}query[MAXN];
struct Mod {
    int x, v, last;
}modify[MAXN];
bool cmp1(Node a, Node b) {
    if(pos[a.l] == pos[b.l]) {
        if(a.r == b.r) return a.x < b.x; else return a.r < b.r;
    }else return pos[a.l] < pos[b.l];
}
inline void Add(int x) {++c[x]; ans += (c[x] == 1);}
inline void Del(int x) {--c[x]; ans -= (c[x] == 0);}
inline void Change(int x, int v) {if(L <= x && x <= R) Add(v), Del(a[x]); a[x] = v;}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), b[i] = a[i];
    block = sqrt(n * 1.0);
    for(int i = 1; i <= n; ++i) pos[i] = (i - 1) / block + 1;
    for(int i = 1; i <= m; ++i) {
        scanf("%s%d%d", ss, &ll, &rr);
        if(ss[0] == 'Q') query[++cnt].l = ll, query[cnt].r = rr, query[cnt].id = cnt, query[cnt].x = num;
        else modify[++num].x = ll, modify[num].v = rr, modify[num].last = b[ll], b[ll] = rr;
    }
    sort(query + 1, query + 1 + cnt, cmp1);
    for(int i = 1; i <= cnt; ++i) {
        while(now < query[i].x) ++now, Change(modify[now].x, modify[now].v);
        while(now > query[i].x) Change(modify[now].x, modify[now].last), --now;
        while(R < query[i].r) ++R, Add(a[R]);
        while(R > query[i].r) Del(a[R]), --R;
        while(L < query[i].l) Del(a[L]), ++L;
        while(L > query[i].l) --L, Add(a[L]);
        data[query[i].id] = ans;
    }
    for(int i = 1; i <= cnt; ++i) {
        printf("%d\n", data[i]);
    }
    return 0;
}

