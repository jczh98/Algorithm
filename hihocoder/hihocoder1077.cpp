#include <bits/stdc++.h>
#define MN 1000100
using namespace std;
typedef long long LL;
int n,q,a[MN];
struct Node
{
    int l,r,minv;
}tree[4*MN];
void PushUp(int x)
{
    tree[x].minv=min(tree[x<<1].minv,tree[x<<1|1].minv);
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;tree[x].minv=INT_MAX;
    if(l==r)tree[x].minv=a[l];
    else
    {
        int mid=(l+r)/2;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
        PushUp(x);
    }
}
void Update(int x,int p,int v)
{
    int L=tree[x].l,R=tree[x].r;
    if(L==R)tree[x].minv=v;
    else
    {
        int mid=(L+R)/2;
        if(p<=mid)Update(x<<1,p,v);
        if(p>mid)Update(x<<1|1,p,v);
        PushUp(x);
    }
}
int Query(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(L==l&&R==r)return tree[x].minv;
    else
    {
        int mid=(L+R)/2;
        if(r<=mid)return Query(x<<1,l,r);
        else if(l>mid)return Query(x<<1|1,l,r);
        else return min(Query(x<<1,l,mid),Query(x<<1|1,mid+1,r));
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    Build(1,1,n);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(x==0)printf("%d\n",Query(1,y,z));
        if(x==1)Update(1,y,z);
    }
    return 0;
}
