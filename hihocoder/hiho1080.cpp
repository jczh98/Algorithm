#include <bits/stdc++.h>
#define MN 100100
using namespace std;
typedef long long LL;
int n,m,p[MN];
struct Node
{
    int l,r,sum,lazy_add,lazy_set;
    void add(int v)
    {
        sum+=(r-l+1)*v;
        lazy_add+=v;
    }
    void sets(int v)
    {
        sum=(r-l+1)*v;
        lazy_set=v;
        lazy_add=0;
    }
}tree[4*MN];
void PushUp(int x)
{
    tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
}
void PushDown(int x)
{
    if(tree[x].lazy_set)
    {
        tree[x<<1].sets(tree[x].lazy_set);
        tree[x<<1|1].sets(tree[x].lazy_set);
        tree[x<<1].lazy_add=tree[x<<1|1].lazy_add=0;
        tree[x].lazy_set=0;
    }
    if(tree[x].lazy_add)
    {
        tree[x<<1].add(tree[x].lazy_add);
        tree[x<<1|1].add(tree[x].lazy_add);
        tree[x].lazy_add=0;
    }
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;
    tree[x].sum=tree[x].lazy_add=tree[x].lazy_set=0;
    if(l==r)tree[x].sum=p[l];
    else
    {
        int mid=(l+r)/2;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
        PushUp(x);
    }
}
void Add(int x,int l,int r,int add)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)tree[x].add(add);
    else
    {
        int mid=(L+R)/2;
        PushDown(x);
        if(l<=mid)Add(x<<1,l,r,add);
        if(mid<r)Add(x<<1|1,l,r,add);
        PushUp(x);
    }
}
void Set(int x,int l,int r,int sets)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)tree[x].sets(sets);
    else
    {
        int mid=(L+R)/2;
        PushDown(x);
        if(l<=mid)Set(x<<1,l,r,sets);
        if(mid<r)Set(x<<1|1,l,r,sets);
        PushUp(x);
    }
}
int Query(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)return tree[x].sum;
    else
    {
        int mid=(L+R)/2;
        int ans=0;
        if(l<=mid)ans+=Query(x<<1,l,r);
        if(mid<r)ans+=Query(x<<1|1,l,r);
        return ans;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+1;i++)scanf("%d",&p[i]);
    Build(1,1,n+1);
    for(int i=1;i<=m;i++)
    {
        int o,l,r,v;scanf("%d%d%d%d",&o,&l,&r,&v);
        if(o==0)
        {
            Add(1,l+1,r+1,v);
            printf("%d\n",Query(1,1,n+1));
        }else
        {
            Set(1,l+1,r+1,v);
            printf("%d\n",Query(1,1,n+1));
        }
    }
    return 0;
}
