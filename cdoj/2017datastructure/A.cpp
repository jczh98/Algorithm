#include <bits/stdc++.h>
#define MN 100000
#define inf 1000000000
using namespace std;
struct Node
{
    int l,r,maxv,minv;
}tree[4*MN];
int a[MN],n,q,ans=0,ql,qr;
void PushUp(int x)
{
    tree[x].maxv=max(tree[x<<1].maxv,tree[x<<1|1].maxv);
    tree[x].minv=min(tree[x<<1].minv,tree[x<<1|1].minv);
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;tree[x].maxv=inf;tree[x].minv=-inf;
    if(l==r)
    {
        tree[x].maxv=tree[x].minv=a[l];
    }else
    {
        int mid=(l+r)/2;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
        PushUp(x);
    }
}
int QueryMax(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(L==l&&r==R)return tree[x].maxv;
    int mid=(L+R)/2;
    if(r<=mid)return QueryMax(x<<1,l,r);
    if(mid<l)return QueryMax(x<<1|1,l,r);
    return max(QueryMax(x<<1,l,mid),QueryMax(x<<1|1,mid+1,r));
}
int QueryMin(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(L==l&&r==R)return tree[x].minv;
    int mid=(L+R)/2;
    if(r<=mid)return QueryMin(x<<1,l,r);
    if(mid<l)return QueryMin(x<<1|1,l,r);
    return min(QueryMin(x<<1,l,mid),QueryMin(x<<1|1,mid+1,r));
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    Build(1,1,n);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&ql,&qr);
        ans=QueryMax(1,ql,qr)-QueryMin(1,ql,qr);
        printf("%d\n",ans);
    }
    return 0;
}
