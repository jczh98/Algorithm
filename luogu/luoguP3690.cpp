#include <bits/stdc++.h>
using namespace std;
/**
 * makeroot(x) 让x成为原树根节点
 * link(x,y) x, y之间连边
 * cut(x,y) x, y删边
 * split(x,y) 找到x, y所对应的路径，访问y得到路径信息
 * findroot(x) 找到x所在原树的根
 * access(x) 从根节点到x拉一条重边
 **/ 
namespace LinkCutTree {
    const int N = 300005;
    int c[N][2], fa[N], rev[N], que[N], top;
    int Xor[N], val[N]; 
    void pushup(int x) {
        Xor[x] = Xor[c[x][0]]^Xor[c[x][1]]^val[x];
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
int n, m, opt, x, y;
int main() {
    using namespace LinkCutTree;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%d", &val[i]), Xor[i] = val[i];
    for(int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &opt, &x, &y);
        if(opt == 0) {
            split(x, y);
            printf("%d\n", Xor[y]);
        }else if(opt == 1) {
            link(x, y);
        }else if(opt == 2) {
            cut(x, y);
        }else {
            access(x); splay(x); val[x] = y; pushup(x);
        }
    }
    return 0;
}