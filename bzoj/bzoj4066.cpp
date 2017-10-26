#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 200005;
int cmp_dim;
struct Node {
    int D[2], Max[2], Min[2], l, r, v, sum;
    int & operator [] (int x) {return D[x];}
    bool operator < (const Node & rhs) const {return D[cmp_dim] < rhs.D[cmp_dim] || D[cmp_dim] == rhs.D[cmp_dim] && D[cmp_dim ^ 1] < rhs.D[cmp_dim ^ 1];}
}kdt[MAXN];
int root = 0, tot = 0;
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
    kdt[x].sum = kdt[x].v + kdt[l].sum + kdt[r].sum;
}
int Build(int l, int r, int dim) {
    if(l > r) return 0;
    int mid = (l + r) >> 1;
    cmp_dim = dim;
    nth_element(kdt + l, kdt + mid, kdt + r + 1);
    kdt[mid].Max[0] = kdt[mid].Min[0] = kdt[mid][0];
    kdt[mid].Max[1] = kdt[mid].Min[1] = kdt[mid][1];
    kdt[mid].sum = kdt[mid].v;
    kdt[mid].l = Build(l, mid - 1, dim ^ 1);
    kdt[mid].r = Build(mid + 1, r, dim ^ 1);
    PushUp(mid);
    return mid;
}
inline void MakeNode(int x, int x1, int y1, int v) {
    kdt[x][0] = x1; kdt[x][1] = y1; kdt[x].v = kdt[x].sum = v;
    for(int i = 0; i <= 1; ++i) kdt[x].Max[i] = kdt[x].Min[i] = kdt[x][i];
}
void Insert(int x, int x1, int y1, int v) {
    MakeNode(x, x1, y1, v);
    if(!root) {
        root = x; return;
    }
    int now = root, dim = 0;
    while(true) {
        kdt[now].Min[0] = min(kdt[now].Min[0], kdt[x].Min[0]);
        kdt[now].Max[0] = max(kdt[now].Max[0], kdt[x].Max[0]);
        kdt[now].Min[1] = min(kdt[now].Min[1], kdt[x].Min[1]);
        kdt[now].Max[1] = max(kdt[now].Max[1], kdt[x].Max[1]);
        kdt[now].sum += kdt[x].sum;
        if(kdt[x][dim] <= kdt[now][dim]) {
            if(kdt[now].l) now = kdt[now].l; else {kdt[now].l = x; break;}
        }else {
            if(kdt[now].r) now = kdt[now].r; else {kdt[now].r = x; break;}
        }
        dim ^= 1;
    }
}
bool InOf(int min_x, int min_y, int max_x, int max_y,int xx1, int yy1, int xx2, int yy2) {
    return min_x >= xx1 && max_x <= xx2 && min_y >= yy1 && max_y <= yy2;
}
bool OutOf(int min_x, int min_y, int max_x, int max_y,int xx1, int yy1, int xx2, int yy2) {
    return max_x < xx1 || min_x > xx2 || max_y < yy1 || min_y > yy2;
}
int last_ans = 0;
void Query(int x, int xx1, int yy1, int xx2, int yy2) {
    int l = kdt[x].l, r = kdt[x].r;
    if(InOf(kdt[x][0], kdt[x][1], kdt[x][0], kdt[x][1], xx1, yy1, xx2, yy2)) last_ans += kdt[x].v;
    if(l) {
        if(InOf(kdt[l].Min[0], kdt[l].Min[1], kdt[l].Max[0], kdt[l].Max[1], xx1, yy1, xx2, yy2)) last_ans += kdt[l].sum;
        else if(OutOf(kdt[l].Min[0], kdt[l].Min[1], kdt[l].Max[0], kdt[l].Max[1], xx1, yy1, xx2, yy2));
        else Query(l, xx1, yy1, xx2, yy2);
    }
    if(r) {
        if(InOf(kdt[r].Min[0], kdt[r].Min[1], kdt[r].Max[0], kdt[r].Max[1], xx1, yy1, xx2, yy2)) last_ans += kdt[r].sum;
        else if(OutOf(kdt[r].Min[0], kdt[r].Min[1], kdt[r].Max[0], kdt[r].Max[1], xx1, yy1, xx2, yy2));
        else Query(r, xx1, yy1, xx2, yy2);
    }
}
int n, opt, xx1, yy1, xx2, yy2, val, m = 10000;
int main() {
    scanf("%d", &n);
    while(true) {
        scanf("%d", &opt);
        if(opt == 3) break;
        if(opt == 1) {
            scanf("%d%d%d", &xx1, &yy1, &val);
            xx1 ^= last_ans; yy1 ^= last_ans; val ^= last_ans;
            ++tot;
            Insert(tot, xx1, yy1, val);
            if(tot == m) {
                root = Build(1, tot, 0);
                m += 10000;
            }
        }else {
            scanf("%d%d%d%d", &xx1, &yy1, &xx2, &yy2);
            xx1 ^= last_ans; yy1 ^= last_ans; xx2 ^= last_ans; yy2 ^= last_ans;
            last_ans = 0;
            Query(root, xx1, yy1, xx2, yy2);;
            printf("%d\n", last_ans);
        }
    }
    return 0;
}