#include <bits/stdc++.h>
#define MN 500500
using namespace std;
int lch[MN],rch[MN],s[MN],v[MN],rnd[MN],w[MN];
int sz=0,root=0;
void Update(int x)
{
    s[x]=s[lch[x]]+s[rch[x]]+w[x];
}
void Lrot(int &x)
{
    int t=rch[x];
    rch[x]=lch[t];
    lch[t]=x;
    Update(x);
    Update(t);
    x=t;
}
void Rrot(int &x)
{
    int t=lch[x];
    lch[x]=rch[t];
    rch[t]=x;
    Update(x);
    Update(t);
    x=t;
}
void Insert(int &x,int val)
{
    if(x==0)
    {
        sz++;
        x=sz;
        s[x]=w[x]=1;
        rnd[x]=rand();
        v[x]=val;
        return;
    }
    s[x]++;
    if(v[x]==val)
    {
        w[x]++;return;
    }else if(v[x]>val)
    {
        Insert(lch[x],val);
        if(rnd[lch[x]]>rnd[x])Rrot(x);
    }else
    {
        Insert(rch[x],val);
        if(rnd[rch[x]]>rnd[x])Lrot(x);
    }
}
int ans=0;
void Query(int x,int k)
{
    if(x==0)return;
    if(k>=v[x])
    {
        ans=v[x];
        Query(rch[x],k);
    }else
    {
        Query(lch[x],k);
    }
}
int n;
int main()
{
    char s[10];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int ki;
        scanf("%s%d",s,&ki);
        if(s[0]=='I')
        {
            Insert(root,ki);
        }else
        {
            ans=0;
            Query(root,ki);
            printf("%d\n",ans);
        }
    }
    return 0;
}
