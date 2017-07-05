#include <bits/stdc++.h>
#define MN 500500
#define inf 10000000
using namespace std;
struct Node
{
    int l,r,sum,mx,lmax,rmax;
    void update(int v)
    {
        sum=lmax=rmax=mx=v;
    }
}tree[4*MN];
int arr[MN],n,m,ans,pre;
void PushUp(int x)
{
    tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
    tree[x].mx=max(max(tree[x<<1].mx,tree[x<<1|1].mx),tree[x<<1].rmax+tree[x<<1|1].lmax);
    tree[x].lmax=max(tree[x<<1].lmax,tree[x<<1].sum+tree[x<<1|1].lmax);
    tree[x].rmax=max(tree[x<<1|1].rmax,tree[x<<1|1].sum+tree[x<<1].rmax);
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;
    if(l==r)
    {
        tree[x].sum=tree[x].lmax=tree[x].rmax=tree[x].mx=arr[l];
    }else
    {
        int mid=(l+r)/2;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
        PushUp(x);
    }
}
void Modify(int x,int pos,int v)
{
    if(tree[x].l==tree[x].r)
    {
        tree[x].update(v);
    }else
    {
        int mid=(tree[x].l+tree[x].r)/2;
        if(pos<=mid)Modify(x<<1,pos,v);
        if(pos>mid)Modify(x<<1|1,pos,v);
        PushUp(x);
    }
}
void Query(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)
    {
        ans=max(ans,max(tree[x].mx,pre+tree[x].lmax));
        pre=max(tree[x].rmax,pre+tree[x].sum);
        return;
    }
    int mid=(L+R)/2;
    if(l<=mid)Query(x<<1,l,r);
    if(r>mid)Query(x<<1|1,l,r);
    PushUp(x);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    Build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int k,a,b;
        scanf("%d%d%d",&k,&a,&b);
        if(k==1)
        {
            ans=pre=-inf;
            Query(1,a,b);
            printf("%d\n",ans);
        }else
        {
            Modify(1,a,b);
        }
    }
    return 0;
}
