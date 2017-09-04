#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
struct Node
{
    int l,r,maxv;
}tree[2000000];
void PushUp(int x)
{
    tree[x].maxv=max(tree[x<<1].maxv,tree[x<<1|1].maxv);
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;tree[x].maxv=0;
    if(l!=r)
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
    if(L==R)tree[x].maxv=v;
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
    if(L==l&&R==r)return tree[x].maxv;
    else
    {
        int mid=(L+R)/2;
        if(r<=mid)return Query(x<<1,l,r);
        else if(l>mid)return Query(x<<1|1,l,r);
        else return max(Query(x<<1,l,mid),Query(x<<1|1,mid+1,r));
    }
}

int n,a[500000],b[500000],c[500000],ans[5000000],maxv;
LL sum;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        Build(1,1,2*n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]-=i,Update(1,i,a[i]);
        //maxv=0;
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        sort(b+1,b+1+n);
        /*for(int i=n;i>=1;i--)
        {
            maxv=max(maxv,a[i]);
            c[i]=max(c[i],maxv);
        }*/
        //for(int i=1;i<=n;i++)cout<<c[i]<<endl;
        //maxv=0;
        for(int i=1;i<=n;i++)
        {
            maxv=Query(1,b[i],n+i);
            Update(1,n+i,maxv-(n+i));
            sum=(sum+maxv)%MOD;
        }
        cout<<sum<<endl;
    }
}
