#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Node
{
    int l,r;
    LL sum,lazy;
    void update(LL v)
    {
        sum+=1LL*(r-l+1)*v;
        lazy+=v;
    }
}tree[400400];
int n,a[100100],m;
void PushUp(int idx)
{
    tree[idx].sum=tree[idx<<1].sum+tree[idx<<1|1].sum;
}
void PushDown(int idx)
{
    LL lazyv=tree[idx].lazy;
    if(lazyv)
    {
        tree[idx<<1].update(lazyv);
        tree[idx<<1|1].update(lazyv);
        tree[idx].lazy=0;
    }
}
void Build(int idx,int l,int r)
{
    tree[idx].l=l;tree[idx].r=r;
    tree[idx].sum=tree[idx].lazy=0;
    if(l==r)tree[idx].sum=a[l];
    else
    {
        int mid=(l+r)/2;
        Build(idx<<1,l,mid);
        Build(idx<<1|1,mid+1,r);
        PushUp(idx);
    }
}
void Update(int idx,int l,int r,LL v)
{
    int L=tree[idx].l,R=tree[idx].r;
    if(l<=L&&R<=r)tree[idx].update(v);
    else
    {
        PushDown(idx);
        int mid=(L+R)/2;
        if(l<=mid)Update(idx<<1,l,r,v);
        if(r>mid)Update(idx<<1|1,l,r,v);
        PushUp(idx);
    }
}
LL Query(int idx,int l,int r)
{
    int L=tree[idx].l,R=tree[idx].r;
    if(l<=L&&R<=r)return tree[idx].sum;
    else
    {
        PushDown(idx);
        LL ans=0;
        int mid=(L+R)/2;
        if(l<=mid)ans+=Query(idx<<1,l,r);
        if(r>mid)ans+=Query(idx<<1|1,l,r);
        PushUp(idx);
        return ans;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    Build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int l,r,v;
        scanf("%d%d%d",&l,&r,&v);
        Update(1,l,r,v);
        printf("%lld\n",Query(1,l,r));
    }
    return 0;
}
