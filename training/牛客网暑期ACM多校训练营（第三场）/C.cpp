#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
const int MAXN = 333333;  
#define m_set(ptr,v,type,size) memset(ptr,v,sizeof(type)*size)  
#define loop(begin,end) for(int i=begin;i<end;i++)  
class SplayTree{  
    #define l(x) (ch[x][0])  
    #define r(x) (ch[x][1])  
    #define mid(x,y) ((x+y)>>1)  
public:  
    int ch[MAXN][2],pre[MAXN];  
    int sz[MAXN],val[MAXN],rev[MAXN],a[MAXN];  
    int root,tot;  
    void init(){  
        m_set(ch,0,int,MAXN*2);  
        m_set(pre,0,int,MAXN);  
        m_set(sz,0,int,MAXN);  
        m_set(val,0,int,MAXN);  
        m_set(rev,0,int,MAXN);  
        root = tot = 0;  
    }  
    void read(int n){  
        a[1] = a[n+2] = 0;  
        loop(2,n+2){ a[i] = i-1; }  
    }  
    void push_up(int rt){  
        sz[rt] = sz[l(rt)]+sz[r(rt)]+1;  
    }  
    void swap(int &x,int &y){  
        int tmp = x;  
        x = y;  
        y = tmp;  
    }  
    void push_down(int rt){  
        if(rt&&rev[rt]){  
            swap(l(rt),r(rt));  
            if(l(rt)) rev[l(rt)] ^= 1;  
            if(r(rt)) rev[r(rt)] ^= 1;  
            rev[rt] = 0;  
        }  
    }  
    void rotate(int x,int f){  
        int y = pre[x];  
        push_down(x);  
        push_down(y);  
        ch[y][!f] = ch[x][f];  
        if(ch[y][!f]) pre[ch[y][!f]] = y;  
        push_up(y);  
        if(pre[y]) ch[pre[y]][r(pre[y])==y] = x;  
        pre[x] = pre[y];  
        ch[x][f] = y;  
        pre[y] = x;  
    }  
    void splay(int x,int goal){  
        push_down(x);  
        while(pre[x]!=goal){  
            int y = pre[x], z = pre[pre[x]];  
            if(z==goal){  
                rotate(x,l(y)==x);  
            }else{  
                int f = l(z)==y;  
                if(ch[y][!f]==x){  
                    rotate(y,f); rotate(x,f);  
                }else{  
                    rotate(x,!f); rotate(x,f);  
                }  
            }  
        }  
        push_up(x);  
        if(goal==0) root = x;  
    }  
    void rotateTo(int k,int goal){  
        int x = root;  
        while(1){  
            push_down(x);  
            int tmp = sz[l(x)]+1;  
            if(k==tmp) break;  
            else if(k<tmp) x = l(x);  
            else{  
                k -= tmp;  
                x = r(x);  
            }  
        }  
        splay(x,goal);  
    }  
    void buildTree(int l,int r,int &rt,int f){  
        if(l>r)return;  
        int m = mid(l,r);  
        rt = ++tot;  
        val[rt] = a[m];  
        pre[rt] = f;  
        buildTree(l,m-1,l(rt),rt);  
        buildTree(m+1,r,r(rt),rt);  
        push_up(rt);  
    }  
    void rangeCut(int l,int r,int goal){  
        rotateTo(l-1,0);  
        rotateTo(r+1,root);  
        push_down(r(root));  
        int x = l(r(root));  
        l(r(root)) = 0;  
        pre[x] = 0;  
        push_up(r(root));  
        push_up(root);  
        rotateTo(goal,0);  
        rotateTo(goal+1,root);  
        push_down(r(root));  
        l(r(root)) = x;  
        pre[x] = r(root);  
        push_up(r(root));  
        push_up(root);  
    }  
    void rangeFlip(int l,int r){  
        rotateTo(l-1,0);  
        rotateTo(r+1,root);  
        push_down(r(root));  
        int x = l(r(root));  
        rev[x] ^= 1;  
    }  
    void dfs(int rt,int &size){  
        if(!rt) return;  
        push_down(rt);  
        dfs(l(rt),size);  
        a[size++] = val[rt];  
        dfs(r(rt),size);  
    }  
    /////////////////debug///////////////////////  
  
}spt;  
int main(){  
    int n,m;  
    scanf("%d%d",&n,&m); 
    spt.init();  
    spt.read(n);  
    spt.buildTree(1,n+2,spt.root,0);  
    char op[5]; int a,b,c;  
    while(m--){  
        scanf("%d%d",&a,&b);  
        spt.rangeCut(a+1,a+b,1);  
    }  
    n = 0;  
    spt.dfs(spt.root,n);  
    loop(1,n-1){  
        if(i!=1)printf(" ");  
        printf("%d",spt.a[i]);  
    }  
    printf("\n");  
    return 0;  
}  