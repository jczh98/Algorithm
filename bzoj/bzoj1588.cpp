#include <bits/stdc++.h>
#define MN 327670
#define INF 1000000000
using namespace std;
int lch[MN],rch[MN],s[MN],w[MN],v[MN],rnd[MN];
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
    Update(x);Update(t);
    x=t;
}
void Rrot(int &x)
{
    int t=lch[x];
    lch[x]=rch[t];
    rch[t]=x;
    Update(x);Update(t);
    x=t;
}
void Insert(int &x,int val)
{
    if(x==0)
    {
        x=++sz;
        s[x]=w[x]=1;
        v[x]=val;
        rnd[x]=rand();
        return;
    }
    s[x]++;
    if(val==v[x]){w[x]++;return;}
    else if(val<v[x])
    {
        Insert(lch[x],val);
        if(rnd[lch[x]]>rnd[x])Rrot(x);
    }else
    {
        Insert(rch[x],val);
        if(rnd[rch[x]]>rnd[x])Lrot(x);
    }
}
int pre=-INF,suc=INF;
void Suc(int x,int val)
{
    if(x==0)return;
    if(val<=v[x])
    {
        suc=v[x];
        Suc(lch[x],val);
    }
    else Suc(rch[x],val);
}
void Pre(int x,int val)
{
    if(x==0)return;
    if(val>=v[x])
    {
        pre=v[x];
        Pre(rch[x],val);
    }
    else Pre(lch[x],val);
}
int n,num,ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num);
        pre=-INF,suc=INF;
        Suc(root,num);Pre(root,num);
        if(i==1)ans+=num;
        else
        {
            ans+=min(suc-num,num-pre);
        }
        Insert(root,num);
    }
    printf("%d\n",ans);
    return 0;
}
