#include <bits/stdc++.h>
#define N 5005000
#define M 5005000
using namespace std;
typedef long long LL;
int n,m,block,a[N],pos[N],num[N]={0};
LL ans=0;
struct Query
{
    int l,r,id;
    LL answer;
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
inline void Update(int x,int d)
{
    ans+=a[x]*(1+2*d*num[a[x]]);
    num[a[x]]+=d;
}
int main()
{
    scanf("%d%d",&n,&m);
    block=ceil(sqrt(1.0*n));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[i]=(i-1)/block;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);Q[i].id=i;
    }
    sort(Q+1,Q+1+m,cmp);
    int l=Q[1].l,r=Q[1].r;
    for(int i=l;i<=r;i++)Update(i,1);
    Q[1].answer=ans;
    for(int i=2;i<=m;i++)
    {
        while(r<Q[i].r)Update(++r,1);
        while(r>Q[i].r)Update(r--,-1);
        while(l<Q[i].l)Update(l++,-1);
        while(l>Q[i].l)Update(--l,1);
        Q[i].answer=ans;
    }
    sort(Q+1,Q+1+m,cmp_id);
    for(int i=1;i<=m;i++)
    {
        cout<<Q[i].answer<<endl;
    }
    return 0;
}
