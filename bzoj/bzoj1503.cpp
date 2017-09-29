#include <bits/stdc++.h>
#define inf 2e9
using namespace std;
typedef long long LL;
const int MAXN = 200005;
int ch[MAXN][2], fa[MAXN], key[MAXN], cnt[MAXN], sz[MAXN];
int root, tot;
inline void Clear(int x) {
    ch[x][0] = ch[x][1] = fa[x] = key [x] = cnt[x] = sz[x] = 0;
}
inline int Get(int x) {
    return ch[fa[x]][1] == x;
}
inline void Update(int x) {
    if(x) {
        sz[x] = cnt[x];
        if(ch[x][0]) sz[x] += sz[ch[x][0]];
        if(ch[x][1]) sz[x] += sz[ch[x][1]];
    }
}
inline void Rotate(int x) {
    int f = fa[x], ff = fa[f], which = Get(x);
    ch[f][which] = ch[x][which ^ 1];
    fa[ch[f][which]] = f;
    ch[x][which ^ 1] = f;
    fa[f] = x;
    fa[x] = ff;
    if(ff) {
        ch[ff][ch[ff][1] == f] = x;
    }
    Update(f);
    Update(x);
}
inline void Splay(int x, int target) {
    while(fa[x] != target) {
        if(fa[fa[x]] != target) {
            Rotate(Get(x) == Get(fa[x]) ? fa[x] : x);
        }
        Rotate(x);
    }
    if(target == 0 ) root = x;
}
inline void Insert(int v) {
    if(root == 0) {
        tot++;
        ch[tot][0] = ch[tot][1] = fa[tot] = 0;
        key[tot] = v;
        cnt[tot] = 1;
        sz[tot] = 1;
        root = tot;
    }else {
        int now = root, f = 0;
        while(true) {
            if(key[now] == v) {
                cnt[now]++;
                Update(now);
                Update(f);
                Splay(now, 0);
                break;
            }
            f = now;
            now = ch[now][key[now] < v];
            if(now == 0) {
                tot++;
                ch[tot][0] = ch[tot][1] = 0;
                key[tot] = v;
                cnt[tot] = 1;
                sz[tot] = 1;
                fa[tot] = f;
                ch[f][key[f] < v] = tot;
                Update(f);
                Splay(tot, 0);
                break;
            }
        }
    }
}
inline int FindByKth(int x) {
    int ans = 0, now = root;
    while(true) {
        if(x < key[now]) {
            now = ch[now][0];
        }else {
            ans += ch[now][0] ? sz[ch[now][0]] : 0;
            if(x == key[now]) {
                Splay(now, 0);
                return ans + 1;
            }
            ans += cnt[now];
            now = ch[now][1];
        }
    }
}
inline int FindNumber(int x) {
    int now = root;
    while(true) {
        if(x < key[now]) {
            now = ch[now][0];
        }else {
            if(x == key[now]) {
                Splay(now, 0);
                return now;
            }
            now = ch[now][1];
        }
    }
}
inline int FindVal(int x) {
    int now = root;
    while(true) {
        if(ch[now][0] && x <= sz[ch[now][0]]) {
            now = ch[now][0];
        }else {
            int t = ch[now][0] ? sz[ch[now][0]] : 0;
            t += cnt[now];
            if(x <= t) {
                return key[now];
            }
            x -= t;
            now = ch[now][1];
        }
    }
}
inline int Pre() {
    int now = ch[root][0];
    while(ch[now][1]) now = ch[now][1];
    return now;
}
inline int Next() {
    int now = ch[root][1];
    while(ch[now][0]) now = ch[now][0];
    return now;
}
inline void Delete(int x) {
    FindNumber(x);
    if (cnt[root] > 1) {
        cnt[root]--;
        return;
    }
    //Only One Point
    if (!ch[root][0] && !ch[root][1]) {
        Clear(root);
        root = 0;
        return;
    }
    //Only One Child
    if (!ch[root][0]) {
        int oldroot = root;
        root = ch[root][1];
        fa[root] = 0;
        Clear(oldroot);
        return;
    } else if (!ch[root][1]) {
        int oldroot = root;
        root = ch[root][0];
        fa[root] = 0;
        Clear(oldroot);
        return;
    }
    //Two Children
    int leftbig = Pre(), oldroot = root;
    Splay(leftbig, 0);
    fa[ch[oldroot][1]] = root;
    ch[root][1] = ch[oldroot][1];
    Clear(oldroot);
    Update(root);
    return;
}
int n, Min, k, det, ans, tot_num;
char s[100];
int main() {
    scanf("%d%d", &n, &Min);
    det = 0;
    Insert(inf);
    Insert(-inf);
    for(int i = 1; i <= n; i++) {
        scanf("%s%d", s, &k);
        if(s[0] == 'I' && k >= Min) {
            tot_num++;
            Insert(k - det);
        }
        if(s[0] == 'A') det += k;
        if(s[0] == 'S') {
            det -= k;
            Insert(Min - det);
            int t1 = FindNumber(-inf), t2 = FindNumber(Min - det);
            Splay(t1, 0);
            Splay(t2, t1);
            ch[ch[root][1]][0] = 0;
            Delete(Min - det);
        }
        if(s[0] == 'F') {
            ans = FindByKth(inf) - 2;
            if(ans < k) {
                printf("-1\n");
                continue;
            }
            printf("%d\n", FindVal(ans + 2 - k) + det);
        }
    }
    printf("%d\n", tot_num - FindByKth(inf) + 2);
    return 0;
}