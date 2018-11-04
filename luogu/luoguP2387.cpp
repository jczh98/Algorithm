#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
namespace LinkCutTree {
    const int N = 200005;
    int c[N][2], fa[N], rev[N], que[N], top;
    int mx[N], val[N]; 
    void pushup(int x) {
        mx[x] = x;
        if(val[mx[c[x][0]]] > val[mx[x]]) mx[x] = mx[c[x][0]];
        if(val[mx[c[x][1]]] > val[mx[x]]) mx[x] = mx[c[x][1]];
    }
    void pushdown(int x) {
        if(rev[x]) {
            rev[c[x][0]]^=1; rev[c[x][1]]^=1; rev[x]^=1;
            swap(c[x][0], c[x][1]);
        }
    }
    bool isroot(int x) {return c[fa[x]][0] != x && c[fa[x]][1] != x;}
    void rotate(int x) {
        int y=fa[x],z=fa[y],l,r;
        if(c[y][0]==x)l=0;else l=1;r=l^1;
        if(!isroot(y)){if(c[z][0]==y)c[z][0]=x;else c[z][1]=x;}
        fa[x]=z;fa[y]=x;fa[c[x][r]]=y;
        c[y][l]=c[x][r];c[x][r]=y;
        pushup(y);pushup(x);
    }
    void splay(int x){
        top=1;que[top]=x;
        for(int i=x;!isroot(i);i=fa[i])que[++top]=fa[i];
        for(int i=top;i;i--)pushdown(que[i]);
        while(!isroot(x)){
            int y=fa[x],z=fa[y];
            if(!isroot(y)){
                if((c[y][0]==x)^(c[z][0]==y))rotate(x);
                else rotate(y);
            }rotate(x);
        }
    }
    void access(int x){for(int t=0;x;t=x,x=fa[x])splay(x),c[x][1]=t,pushup(x);}
    void makeroot(int x){access(x);splay(x);rev[x]^=1;}
    int findroot(int x){access(x);splay(x);while(c[x][0])x=c[x][0];return x;}
    void split(int x,int y){makeroot(x);access(y);splay(y);}
    void cut(int x,int y){makeroot(x);if(findroot(y)==x&&c[y][0]==x&&!c[x][1]&&fa[x]==y)c[y][0]=0,fa[x]=0,pushup(y);}
    void link(int x,int y){makeroot(x);if(findroot(y)!=x) fa[x]=y;}
}
using namespace LinkCutTree;
struct edge{
    int u, v, a, b;
    bool operator < (const edge& rhs) const {
        return a < rhs.a;
    }
}edg[N];
int pa[N];
int find(int x) {
    return pa[x] == x ? pa[x] : pa[x] = find(pa[x]);
}
int query(int x, int y) {
    split(x, y); return mx[y];
}
int n, m;
int ans = inf;
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d", &edg[i].u, &edg[i].v, &edg[i].a, &edg[i].b);
    }
    for(int i = 1; i <= n; ++i) pa[i] = i;
    sort(edg+1, edg+1+m);
    for(int i = 1; i <= m; ++i) {
        int u = edg[i].u, v = edg[i].v;
        if(find(u) == find(v)) {
            int t = query(u, v);
            if(val[t] > edg[i].b) {
                cut(t, edg[t-n].u);
                cut(t, edg[t-n].v);
            } else {
                if(find(1) == find(n)) ans = min(ans, edg[i].a + val[query(1, n)]);
                continue;
            }
        } else {
            pa[find(u)] = v;
        }
        val[n+i] = edg[i].b; mx[n+i]=n+i;
        link(u,n+i); link(n+i,v);
        if(find(1) == find(n)) ans = min(ans, edg[i].a + val[query(1, n)]);
    }
    if(ans == inf) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
