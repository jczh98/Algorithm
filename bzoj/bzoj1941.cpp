#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
const int MAXM = 500005;
const int inf = 0x7f7f7f7f;
int cmp_dim;
struct Node {
    int D[2], Max[2], Min[2], l, r;
    int & operator [] (int x) {return D[x];}
    bool operator < (const Node & rhs) const {return D[cmp_dim] < rhs.D[cmp_dim];}
}kdt[MAXN + MAXM], data[MAXN];
int root = 0;
inline void MakeNode(int x, int x1, int y1) {
    kdt[x][0] = x1; kdt[x][1] = y1;
    for(int i = 0; i <= 1; ++i) kdt[x].Max[i] = kdt[x].Min[i] = kdt[x][i];
}
inline void PushUp(int x) {
    int l = kdt[x].l, r = kdt[x].r;
    for(int i = 0; i <= 1; ++i) {
        if(l) {
            kdt[x].Max[i] = max(kdt[x].Max[i], kdt[l].Max[i]);
            kdt[x].Min[i] = min(kdt[x].Min[i], kdt[l].Min[i]);
        }
        if(r) {
            kdt[x].Min[i] = min(kdt[x].Min[i], kdt[r].Min[i]);
            kdt[x].Max[i] = max(kdt[x].Max[i], kdt[r].Max[i]);
        }
    }
}
int Build(int l, int r, int now) {
    if(l > r) return 0;
    int mid = (l + r) >> 1;
    cmp_dim = now;
    nth_element(data + l, data + mid, data + r + 1);
    kdt[mid] = data[mid];
    kdt[mid].l = Build(l, mid - 1, now ^ 1);
    kdt[mid].r = Build(mid + 1, r, now ^ 1);
    PushUp(mid);
    return mid;
}
int dis(Node a, Node b) {return abs(a[0] - b[0]) + abs(a[1] - b[1]);}
int DisMin(int x, Node p){
    int tmp = 0;
    for (int i = 0; i <= 1; i++)
        tmp += max(0, kdt[x].Min[i] - p[i]);
    for (int i = 0; i < 2; i++)
        tmp += max(0, p[i] - kdt[x].Max[i]);
    return tmp;
}
int ansMin;
int QueryMin(int rt, Node p) {
    int d = dis(kdt[rt], p), dl = inf, dr = inf;
    if(d) ansMin = min(ansMin, d);
    if(kdt[rt].l) dl = DisMin(kdt[rt].l, p);
    if(kdt[rt].r) dr = DisMin(kdt[rt].r, p);
    if(dl < dr) {
        if(dl < ansMin) QueryMin(kdt[rt].l, p);
        if(dr < ansMin) QueryMin(kdt[rt].r, p);
    }else {
        if(dr < ansMin) QueryMin(kdt[rt].r, p);
        if(dl < ansMin) QueryMin(kdt[rt].l, p);
    }
}
int DisMax(int now,Node p)
{
    int dis=0;
    dis+=max(abs(kdt[now].Max[0]-p[0]),abs(kdt[now].Min[0]-p[0]));
    dis+=max(abs(kdt[now].Max[1]-p[1]),abs(kdt[now].Min[1]-p[1]));
    return dis;
}
int ansMax;
int QueryMax(int rt, Node p) {
    int d = dis(kdt[rt], p), dl = 0, dr = 0;
    ansMax = max(ansMax, d);
    if(kdt[rt].l) dl = DisMax(kdt[rt].l, p);
    if(kdt[rt].r) dr = DisMax(kdt[rt].r, p);
    if(dl > dr) {
        if(dl > ansMax) QueryMax(kdt[rt].l, p);
        if(dr > ansMax) QueryMax(kdt[rt].r, p);
    }else {
        if(dr > ansMax) QueryMax(kdt[rt].r, p);
        if(dl > ansMax) QueryMax(kdt[rt].l, p);
    }
}
int n, m, x, y, ans = inf;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &x, &y);
        data[i][0] = data[i].Min[0] = data[i].Max[0] = x;
        data[i][1] = data[i].Min[1] = data[i].Max[1] = y;
    }
    root = Build(1, n, 0);
    for(int i = 1; i <= n; ++i) {
        ansMin = inf, ansMax = 0;
        QueryMax(root, data[i]); QueryMin(root, data[i]);
        ans = min(ans, abs(ansMax - ansMin));
    }
    printf("%d\n", ans);
    return 0;
}