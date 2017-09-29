#include <bits/stdc++.h>
#define MN 1100
using namespace std;
struct Seg
{
    int x1,x2,y;
    int flag;
    bool operator < (const Seg &rhs)const
    {
        return y<rhs.y;
    }
}seg[2*MN];
int x_1,y_1,x_2,y_2,x_p[2*MN],ans;
int n;
struct Node
{
    int l,r,cover;double sum;
    void update(int v)
    {
        cover+=v;
    }
}tree[8*MN];
void PushUp(int x)
{
    if(tree[x].cover>0)
    {
        tree[x].sum=x_p[tree[x].r]-x_p[tree[x].l-1];
    }else if(tree[x].l==tree[x].r)
    {
        tree[x].sum=0;
    }else tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
}
void Build(int x,int l,int r)
{
    tree[x].l=l;tree[x].r=r;tree[x].cover=0;tree[x].sum=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        Build(x<<1,l,mid);
        Build(x<<1|1,mid+1,r);
    }
}
void Modify(int x,int l,int r,int v)
{
    int L=tree[x].l,R=tree[x].r;
    if(l<=L&&R<=r)
    {
        tree[x].update(v);
    }else
    {
        int mid=(L+R)/2;
        if(l<=mid)Modify(x<<1,l,r,v);
        if(r>mid)Modify(x<<1|1,l,r,v);
    }
    PushUp(x);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0){
            printf("*\n");
            break;
        }
        int cnt=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&x_1,&y_1,&x_2,&y_2);
            x_p[cnt]=x_1;seg[cnt].x1=x_1;seg[cnt].x2=x_2;seg[cnt].y=y_1;seg[cnt].flag=1;cnt++;
            x_p[cnt]=x_2;seg[cnt].x1=x_1;seg[cnt].x2=x_2;seg[cnt].y=y_2;seg[cnt].flag=-1;cnt++;
        }
        sort(seg+1,seg+cnt);
        sort(x_p+1,x_p+cnt);
        ans=0;
        Build(1,1,cnt-1);
        for(int i=1;i<cnt-1;i++)
        {
            int l=lower_bound(x_p+1,x_p+cnt,seg[i].x1)-x_p+1,r=lower_bound(x_p+1,x_p+cnt,seg[i].x2)-x_p;
            if(l<=r)Modify(1,l,r,seg[i].flag);
            ans+=tree[1].sum*(seg[i+1].y-seg[i].y);
        }
        printf("%d\n",ans);
    }
    return 0;
}