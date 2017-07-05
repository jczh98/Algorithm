#include <bits/stdc++.h>
#define MN 100100
using namespace std;
struct Node
{
    int l0,l1,r0,r1,m0,m1,lazy,l,r;
    void update()
    {
        lazy^=1;
        swap(l0,l1);swap(r0,r1);swap(m0,m1);
    }
}tree[4*MN];
int arr[MN],n,m;
void PushUp(int x)
{
    tree[x].l0=tree[x<<1].l0;
    if(tree[x<<1].r-tree[x<<1].l+1==tree[x<<1].l0)
    {
        tree[x].l0+=tree[x<<1|1].l0;
    }
    tree[x].l1=tree[x<<1].l1;
    if(tree[x<<1].r-tree[x<<1].l+1==tree[x<<1].l1)
    {
        tree[x].l1+=tree[x<<1|1].l1;
    }
    tree[x].r0=tree[x<<1|1].r0;
    if(tree[x<<1|1].r-tree[x<<1|1].l+1==tree[x<<1|1].r0)
    {
        tree[x].r0+=tree[x<<1].r0;
    }
    tree[x].r1=tree[x<<1|1].r1;
    if(tree[x<<1|1].r-tree[x<<1|1].l+1==tree[x<<1|1].r1)
    {
        tree[x].r1+=tree[x<<1].r1;
    }
    tree[x].m0=max(max(tree[x<<1].m0,tree[x<<1|1].m0),tree[x<<1].r0+tree[x<<1|1].l0);
    tree[x].m1=max(max(tree[x<<1].m1,tree[x<<1|1].m1),tree[x<<1].r1+tree[x<<1|1].l1);
}
void PushDown(int x)
{
    if(tree[x].lazy==1)
    {
        tree[x<<1].lazy^=1;
        tree[x<<1|1].lazy^=1;
        tree[x].lazy=0;
        swap(tree[x<<1].l0,tree[x<<1].l1);
        swap(tree[x<<1].r0,tree[x<<1].r1);
        swap(tree[x<<1].m0,tree[x<<1].m1);
        swap(tree[x<<1|1].l0,tree[x<<1|1].l1);
        swap(tree[x<<1|1].r0,tree[x<<1|1].r1);
        swap(tree[x<<1|1].m0,tree[x<<1|1].m1);
    }
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;tree[x].lazy=0;
    if(l==r)
    {
        tree[x].l0=tree[x].r0=tree[x].m0=arr[l]^1;
        tree[x].l1=tree[x].r1=tree[x].m1=arr[l];
    }else
    {
        int mid=(l+r)/2;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
        PushUp(x);
    }
}
void Modify(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)
    {
        tree[x].update();
    }else
    {
        int mid=(L+R)/2;
        PushDown(x);
        if(l<=mid)Modify(x<<1,l,r);
        if(r>mid)Modify(x<<1|1,l,r);
        PushUp(x);
    }
}
int Query(int x,int l,int r)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)return tree[x].m1;
    else
    {
        int mid=(L+R)/2;
        PushDown(x);
        int ll=0,rr=0,a=0,b=0;
        if(l<=mid)ll=Query(x<<1,l,r);
        if(r>mid)rr=Query(x<<1|1,l,r);
        if(l<=mid&&mid<r)
        {
            a=tree[x<<1].r1;
            if(a>tree[x<<1].r-l+1)a=tree[x<<1].r-l+1;
            b=tree[x<<1|1].l1;
            if(b>r-tree[x<<1|1].l+1)b=r-tree[x<<1|1].l+1;
        }
        return max(max(ll,rr),a+b);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&arr[i]);
    Build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int k,l,r;
        scanf("%d%d%d",&k,&l,&r);
        if(k==1)Modify(1,l,r);
        if(k==0)
        {
            printf("%d\n",Query(1,l,r));
        }
    }
    return 0;
}
