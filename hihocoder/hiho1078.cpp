#include <bits/stdc++.h>
#define MN 1000100
using namespace std;
typedef long long LL;
int n,q,a[MN];
struct Node
{
    int l,r;
    LL sum,lazy;
    void update(LL v)
    {
        sum=1LL*(r-l+1)*v;
        lazy=v;
    }
}tree[MN*4];
void PushUp(int x)
{
    tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
}
void PushDown(int x)
{
    LL lazyv=tree[x].lazy;
    if(lazyv)
    {
        tree[x<<1].update(lazyv);
        tree[x<<1|1].update(lazyv);
        tree[x].lazy=0;
    }
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;
    tree[x].sum=tree[x].lazy=0;
    if(l==r)tree[x].sum=a[l];
    else
    {
        int mid=(l+r)/2;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
        PushUp(x);
    }
}
void Update(int x,int l,int r,int v)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)tree[x].update(v);
    else
    {
        int mid=(L+R)/2;
        PushDown(x);
        if(l<=mid)Update(x<<1,l,r,v);
        if(r>mid)Update(x<<1|1,l,r,v);
        PushUp(x);
    }
}
LL Query(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)return tree[x].sum;
    else
    {
        LL ans=0;
        int mid=(L+R)/2;
        PushDown(x);
        if(l<=mid)ans+=Query(x<<1,l,r);
        if(r>mid)ans+=Query(x<<1|1,l,r);
        PushUp(x);
        return ans;
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
        int x,y,z,k;
        scanf("%d",&x);
        if(x==0)
        {
            scanf("%d%d",&y,&z);
            printf("%lld\n",Query(1,y,z));
        }
        if(x==1)
        {
            scanf("%d%d%d",&y,&z,&k);
            Update(1,y,z,k);
        }
    }
    return 0;
}
