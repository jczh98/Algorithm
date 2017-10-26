#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int MAXQ = MAXN + MAXN * 4;
const int MAXL = 10000005;
int n, m, a, b, c, d, cnt = 0, qid = 0, C[MAXL], ans[MAXN], max_y;
struct Node {
    int type, x, y, v, qid;
    bool operator < (const Node & rhs) const {return x == rhs.x ? type < rhs.type : x < rhs.x;}
}query[MAXQ], tmp[MAXQ];
inline void SetZero(int x) {for(; x <= max_y; x += (x & (-x))) if(C[x]) C[x] = 0; else break;}
inline void Update(int x, int v) {for(; x <= max_y; x += (x & (-x))) C[x] += v;}
inline int Query(int x) {int ret = 0; for(; x > 0; x -= (x & (-x))) ret += C[x]; return ret;}
void CDQ(int l, int r) {
    if(l >= r) return;
    int m = (l + r) >> 1;
    CDQ(l, m); CDQ(m + 1, r);
    int l1 = l, l2 = m + 1, cur = l;
    while(l1 <= m && l2 <= r) {
        if(query[l1] < query[l2]) {
            if(query[l1].type == 0) Update(query[l1].y, 1);
            tmp[cur++] = query[l1++];
        }else {
            if(query[l2].type == 1) ans[query[l2].qid] += query[l2].v * Query(query[l2].y);
            tmp[cur++] = query[l2++];
        }
    }
    while(l1 <= m) tmp[cur++] = query[l1++];
    while(l2 <= r) {
        if(query[l2].type == 1) ans[query[l2].qid] += query[l2].v * Query(query[l2].y);
        tmp[cur++] = query[l2++];
    }
    for(int i = l; i <= r; ++i) {
        SetZero(tmp[i].y); query[i] = tmp[i];
    }
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &a, &b);++a;++b;
        max_y = max(b, max_y);
        query[++cnt] = (Node){0, a, b, 0, 0};
    }
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d", &a, &b, &c, &d);++a;++b;++c;++d;
        max_y = max(max_y, max(b, d));
        query[++cnt] = (Node){1, c, d, 1, ++qid};
        query[++cnt] = (Node){1, a - 1, b - 1, 1, qid};
        query[++cnt] = (Node){1, a - 1, d, -1, qid};
        query[++cnt] = (Node){1, c, b - 1, -1, qid};
    }
    CDQ(1, cnt);
    for(int i = 1; i <= qid; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
