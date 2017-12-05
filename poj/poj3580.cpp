#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define inf 0x7f7f7f7f
using namespace std;
const int N = 800005;
int n, m, a[N];
int ch[N][2], fa[N], key[N], rev[N], sz[N], Min[N], add[N];
int root, tot;
inline int get(int x) {return ch[fa[x]][1] == x;} // left is 0, right is 1
inline void pushup(int x) {
    sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
    Min[x] = key[x];
    if(ch[x][0]) Min[x] = min(Min[x], Min[ch[x][0]]);
    if(ch[x][1]) Min[x] = min(Min[x], Min[ch[x][1]]);
}
inline void update_add(int x,int add_) {key[x] += add_; add[x] += add_; Min[x] += add_;}
inline void pushdown(int x) {
    if(!x) return;
    if(add[x]) {
        if(ch[x][0]) {update_add(ch[x][0], add[x]);}
        if(ch[x][1]) {update_add(ch[x][1], add[x]);}
        add[x] = 0;
    }
    if(rev[x]) {
        rev[x] = 0;
        swap(ch[x][0], ch[x][1]);
        rev[ch[x][0]] ^= 1; rev[ch[x][1]] ^= 1;
    }
}
inline void rotate(int x) {
    int f = fa[x], ff = fa[f], which = get(x);
    pushdown(f); pushdown(x);
    ch[f][which] = ch[x][which ^ 1];
    fa[ch[f][which]] = f;
    ch[x][which ^ 1] = f;
    fa[f] = x; fa[x] = ff;
    if(ff) ch[ff][ch[ff][1] == f] = x;
    pushup(f); pushup(x);
}
inline void splay(int x, int target) {
    while(fa[x] != target) {
        if(fa[fa[x]] != target) {
            rotate((get(x) == get(fa[x])) ? fa[x] : x);
        }
        rotate(x);
    }
    if(!target) root = x;
}
inline int newnode(int v, int f) {
    int x = ++tot;
    ch[x][0] = ch[x][1] = 0; fa[x] = f;
    key[x] = Min[x] = v; sz[x] = 1; add[x] = rev[x] = 0;
    return x;
}
int build(int l, int r, int f) {
    if(l > r) return 0;
    int mid = (l + r) / 2;
    int x = newnode(a[mid], f);
    ch[x][0] = build(l, mid - 1, x);
    ch[x][1] = build(mid + 1, r, x);
    pushup(x);
    return x;
}
inline void init() {tot = 0; root = build(0, n + 1, 0);}
inline int get_kth(int x, int k) {
    if(!x) return 0;
    while(1) {
        pushdown(x);
        if(k == sz[ch[x][0]] + 1) break;
        if(k > sz[ch[x][0]] + 1) {
            k -= sz[ch[x][0]] + 1; x = ch[x][1];
        }else x = ch[x][0];
    }
    return x;
}
char opt[20]; int L, R, d;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    a[0] = -inf; a[n + 1] = inf;
    init();
    scanf("%d", &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%s", opt);
        if(!strcmp(opt, "ADD")) {
            scanf("%d%d%d", &L, &R, &d);
            splay(get_kth(root, L), 0); splay(get_kth(root, R + 2), root);
            update_add(ch[ch[root][1]][0], d); 
            pushup(ch[root][1]); pushup(root);
        }else if(!strcmp(opt, "REVERSE")) {
            scanf("%d%d", &L, &R);
            splay(get_kth(root, L), 0); splay(get_kth(root, R + 2), root);
            rev[ch[ch[root][1]][0]] ^= 1;
            pushup(ch[root][1]); pushup(root);
        }else if(!strcmp(opt, "REVOLVE")) {
            scanf("%d%d%d", &L, &R, &d);
            d = (d % (R - L + 1) + (R - L + 1)) % (R - L + 1);
            if(!d) continue;
            splay(get_kth(root, R - d + 1), 0); splay(get_kth(root, R + 2), root);
            int tmp = ch[ch[root][1]][0];
            ch[ch[root][1]][0] = 0;
            pushup(ch[root][1]); pushup(root);
            splay(get_kth(root, L), 0); splay(get_kth(root, L + 1), root);
            ch[ch[root][1]][0] = tmp; fa[tmp] = ch[root][1];
            pushup(ch[root][1]); pushup(root);
        }else if(!strcmp(opt, "INSERT")) {
            scanf("%d%d", &L, &R);
            splay(get_kth(root, L + 1), 0); splay(get_kth(root, L + 2), root);
            ch[ch[root][1]][0] = newnode(R, ch[root][1]);
            pushup(ch[root][1]); pushup(root);
        }else if(!strcmp(opt, "DELETE")) {
            scanf("%d%d", &L);
            splay(get_kth(root, L), 0); splay(get_kth(root, L + 2), root);
            ch[ch[root][1]][0] = 0;
            pushup(ch[root][1]); pushup(root);
        }else if(!strcmp(opt, "MIN")) {
            scanf("%d%d", &L, &R);
            splay(get_kth(root, L), 0); splay(get_kth(root, R + 2), root);
            printf("%d\n", Min[ch[ch[root][1]][0]]);
        }
    }
    return 0;
}