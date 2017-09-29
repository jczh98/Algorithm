#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;
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
inline void Splay(int x) {
    while(fa[x]) {
        if(fa[fa[x]]) {
            Rotate(Get(x) == Get(fa[x]) ? fa[x] : x);
        }
        Rotate(x);
    }
    root = x;
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
                Splay(now);
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
                Splay(tot);
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
                Splay(now);
                return ans + 1;
            }
            ans += cnt[now];
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
    FindByKth(x);
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
    Splay(leftbig);
    fa[ch[oldroot][1]] = root;
    ch[root][1] = ch[oldroot][1];
    Clear(oldroot);
    Update(root);
    return;
}
int n, op, x;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &op, &x);
        switch (op) {
            case 1: Insert(x); break;
            case 2: Delete(x); break;
            case 3: printf("%d\n", FindByKth(x)); break;
            case 4: printf("%d\n", FindVal(x)); break;
            case 5: {
                Insert(x);
                printf("%d\n", key[Pre()]);
                Delete(x);
                break;
            }
            case 6: {
                Insert(x);
                printf("%d\n", key[Next()]);
                Delete(x);
                break;
            }
        }
    }
    return 0;
}

