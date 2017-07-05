#include <bits/stdc++.h>
#define MN 100100
#define MOD 10007
using namespace std;
typedef long long LL;
int n,q,x,v;
struct Node
{
    int l,r,sum,lans,rans,mans;
}tree[4*MN];
void PushUp(int x)
{
    tree[x].mans=(tree[x<<1].mans*tree[x<<1|1].mans)%MOD;
    tree[x].sum=(tree[x<<1].sum+tree[x<<1|1].sum+tree[x<<1].rans*tree[x<<1|1].lans)%MOD;
    tree[x].lans=(tree[x<<1].lans+tree[x<<1].mans*tree[x<<1|1].lans)%MOD;
    tree[x].rans=(tree[x<<1|1].rans+tree[x<<1].rans*tree[x<<1|1].mans)%MOD;
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;
    tree[x].sum=tree[x].mans=tree[x].lans=tree[x].rans=0;
    if(l<r)
    {
        int mid=(l+r)>>1;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
        PushUp(x);
    }
}
void Update(int x,int p,int v)
{
    int L=tree[x].l,R=tree[x].r;
    if(L==R)tree[x].sum=tree[x].mans=tree[x].lans=tree[x].rans=v%MOD;
    else
    {
        int mid=(L+R)>>1;
        if(p<=mid)Update(x<<1,p,v);
        if(p>mid)Update(x<<1|1,p,v);
        PushUp(x);
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    Build(1,1,n);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&v);
        Update(1,x,v);
        printf("%d\n",tree[1].sum);
    }
    return 0;
}
