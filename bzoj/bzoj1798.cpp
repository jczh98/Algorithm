#include <bits/stdc++.h>
#define MN 100100
using namespace std;
typedef long long LL;
int a[MN],n,m,o,l,r,c,P;
struct Node
{
    int l,r;
    LL sum,ladd,lmul;
    void update(LL add,LL mul)
    {
        ladd=((mul%P)*(ladd%P)%P+add%P)%P;
        lmul=((mul%P)*(lmul%P))%P;
        sum=((1ll*(r-l+1)%P)*(add%P))%P+((mul%P)*(sum%P))%P;
    }
}tree[4*MN];
void PushUp(int x)
{
    tree[x].sum=(tree[x<<1].sum%P+tree[x<<1|1].sum%P)%P;
}
void PushDown(int x)
{
    if(tree[x].lmul!=1||tree[x].ladd!=0)
    {
        int mul=tree[x].lmul,add=tree[x].ladd;
        tree[x<<1].update(add,mul);
        tree[x<<1|1].update(add,mul);
        tree[x].lmul=1;
        tree[x].ladd=0;
    }
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;tree[x].sum=0;tree[x].ladd=0;tree[x].lmul=1;
    if(l==r)tree[x].sum=a[l];
    else
    {
        int mid=(l+r)/2;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
        PushUp(x);
    }
}
void Update(int x,int l,int r,LL add,LL mul)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)tree[x].update(add,mul);
    else
    {
        int mid=(L+R)/2;
        PushDown(x);
        if(l<=mid)Update(x<<1,l,r,add,mul);
        if(mid<r)Update(x<<1|1,l,r,add,mul);
        PushUp(x);
    }
}
int Query(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)return tree[x].sum;
    else
    {
        LL ans=0;
        PushDown(x);
        int mid=(L+R)/2;
        if(l<=mid)ans=(ans%P+Query(x<<1,l,r)%P)%P;
        if(mid<r)ans=(ans%P+Query(x<<1|1,l,r)%P)%P;
        PushUp(x);
        return ans;
    }
}
int main()
{
    scanf("%d%d",&n,&P);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    Build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&o);
        if(o==1)
        {
            scanf("%d%d%d",&l,&r,&c);
            Update(1,l,r,0,c);
        }else if(o==2)
        {
            scanf("%d%d%d",&l,&r,&c);
            Update(1,l,r,c,1);
        }else
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",Query(1,l,r));
        }
    }
    return 0;
}
