#include <bits/stdc++.h>
struct Node
{
    int l,r,sum;
}t[1000000];

void Build(int idx,int l,int r)
{
    t[idx].l=l;t[idx].r=r;
    if(l!=r)
    {
        int mid=(l+r)/2;
        Build(2*idx,l,mid);
        Build(2*idx+1,mid+1,r);
    }
    t[idx].sum=t[2*idx].sum+t[2*idx+1].sum;
}

void Update(int idx,int pos,int v)
{
    if(t[idx].l==t[idx].r)t[idx].sum+=v;
    else
    {
        int mid=(t[idx].l+t[idx].r)/2;
        if(pos<=mid)Update(2*idx,pos,v);
        else Update(2*idx+1,pos,v);
        t[idx].sum=t[2*idx].sum+t[2*idx+1].sum;
    }
}

int Query(int idx,int l,int r)
{
    if(t[idx].l==l&&t[idx].r==r) return t[idx].sum;
    else
    {
        int mid=(t[idx].l+t[idx].r)/2;
        if(r<=mid)return Query(2*idx,l,r);
        else if(l>mid) return Query(2*idx+1,l,r);
        else return Query(2*idx,l,mid)+Query(2*idx+1,mid+1,r);
    }
}

int T,n,kase=1;
char s[10000];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(t,0,sizeof(t));
        printf("Case %d:\n",kase++);
        scanf("%d",&n);
        Build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            Update(1,i,x);
        }
        while(scanf("%s",s))
        {
            int x,y;
            if(s[0]=='E')break;
            else if(s[0]=='A')
            {
                scanf("%d%d",&x,&y);
                Update(1,x,y);
            }else if(s[0]=='S')
            {
                scanf("%d%d",&x,&y);
                Update(1,x,-y);
            }else if(s[0]=='Q')
            {
                scanf("%d%d",&x,&y);
                printf("%d\n",Query(1,x,y));
            }
        }
    }
    return 0;
}
