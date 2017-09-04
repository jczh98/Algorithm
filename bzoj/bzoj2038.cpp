#include <bits/stdc++.h>
#define N 500500
#define M 500500
using namespace std;
typedef long long LL;
inline LL Gcd(LL a,LL b)
{
    return b==0?a:Gcd(b,a%b);
}
int n,m,block,color[N],pos[N],num[N]={0},last_r,last_l;
LL ans=0;
struct Query
{
    int l,r,id;
    LL up,down;
    void modify()
    {
        LL g=Gcd(up,down);
        up/=g,down/=g;
    }
}Q[M];
bool cmp(Query a,Query b)
{
    if(pos[a.l]==pos[b.l]) return a.r<b.r;
    else return pos[a.l]<pos[b.l];
}
bool cmp_id(Query a,Query b)
{
    return a.id<b.id;
}
void Update(int x,int d)
{
    ans=ans+num[color[x]]*2*d+1;
    num[color[x]]+=d;
}
int main()
{
    scanf("%d%d",&n,&m);
    block=ceil(sqrt(1.0*n));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&color[i]);
        pos[i]=(i-1)/block;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);Q[i].id=i;
    }
    sort(Q+1,Q+1+m,cmp);
    last_r=0;last_l=1;
    for(int i=1;i<=m;i++)
    {
        if(Q[i].l==Q[i].r)
        {
            Q[i].up=0;Q[i].down=1;continue;
        }
        if(last_r<Q[i].r)
        {
            for(int j=last_r+1;j<=Q[i].r;j++)Update(j,1);
        }else
        {
            for(int j=last_r;j>Q[i].r;j--)Update(j,-1);
        }
        if(last_l<Q[i].l)
        {
            for(int j=last_l;j<Q[i].l;j++)Update(j,-1);
        }else
        {
            for(int j=last_l-1;j>=Q[i].l;j--)Update(j,1);
        }
        Q[i].up=ans-(Q[i].r-Q[i].l+1);Q[i].down=(LL)(Q[i].r-Q[i].l+1)*(LL)(Q[i].r-Q[i].l);
        last_l=Q[i].l;last_r=Q[i].r;
        Q[i].modify();
    }
    sort(Q+1,Q+1+m,cmp_id);
    for(int i=1;i<=m;i++)
    {
        printf("%lld/%lld\n",Q[i].up,Q[i].down);
    }
    return 0;
}
