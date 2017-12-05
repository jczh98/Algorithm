#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int N = 500005;
int ch[N][2], fa[N], key[N], lazy[N], sz[N];
int root, tot;
inline int get(int x) {return ch[fa[x]][1] == x;} // left is 0, right is 1
inline void pushup(int x) {
    sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1;
}
inline void pushdown(int x) {
    if(lazy[x]) {
        lazy[x] = 0;
        swap(ch[x][0], ch[x][1]);
        lazy[ch[x][0]] ^= 1; lazy[ch[x][1]] ^= 1;
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
inline int newnode(int v, int f) {
    int x = ++tot;
    ch[x][0] = ch[x][1] = 0; fa[x] = f;
    key[x] = v; sz[x] = 1; lazy[x] = 0;
    return x;
}
int build(int l, int r, int f) {
    if(l > r) return 0;
    int mid = (l + r) / 2;
    int x = newnode(mid, f);
    ch[x][0] = build(l, mid - 1, x);
    ch[x][1] = build(mid + 1, r, x);
    pushup(x);
    return x;
}
inline void init(int x) {root = tot = 0; root = build(0, x + 1, 0);}
inline void cut(int l, int r, int c) {
    splay(get_kth(root, l), 0); splay(get_kth(root, r + 2), root);
    int tmp = ch[ch[root][1]][0];
    ch[ch[root][1]][0] = 0;
    pushup(ch[root][1]); pushup(root);
    splay(get_kth(root, c + 1), 0); splay(get_kth(root, c + 2), root);
    fa[tmp] = ch[root][1];
    ch[ch[root][1]][0] = tmp;
    pushup(ch[root][1]); pushup(root);
}
inline void filp(int l, int r) {
    splay(get_kth(root, l), 0); splay(get_kth(root, r + 2), root);
    lazy[ch[ch[root][1]][0]] ^= 1;
    pushup(ch[root][1]); pushup(root);
}
int n, m, a, b, c;
int cnt;
void out(int x){
    if (!x) return;
    pushdown(x);
    out(ch[x][0]);
    if (key[x] >= 1 && key[x] <= n) {
        cnt++;
        printf("%d", key[x]);
        if (cnt < n) printf(" ");
        else puts("");
    }
    out(ch[x][1]);
}
char opt[20];
int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        if(n == -1 && m == -1) break;
        init(n);
        for(int i = 1; i <= m ;++i) {
            scanf("%s", opt);
            if(opt[0] == 'C') {
                scanf("%d%d%d", &a, &b, &c); cut(a, b, c);
            }else scanf("%d%d", &a, &b, &c), filp(a, b);
        }     
        cnt = 0; out(root);   
    }
    return 0;
}