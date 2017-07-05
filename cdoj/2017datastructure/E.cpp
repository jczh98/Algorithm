#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,c[100100],rk[100100];
LL ans=0;
int Lowbit(int x){return x&(-x);}
struct Node
{
    int v,num;
}a[100100],b[100100];
int cmp(Node x,Node y)
{
    return x.v<y.v;
}
void Add(int k,int num)
{
    while(k<=n)
    {
        c[k]+=num;
        k+=Lowbit(k);
    }
}
LL Sum(int k)
{
    LL sum=0;
    while(k>0)
    {
        sum+=c[k];
        k-=Lowbit(k);
    }
    return sum;
}
int main()
{
    memset(c,0,sizeof(c));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].v);a[i].num=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i].v);b[i].num=i;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        rk[a[i].num]=b[i].num;
    }
    for(int i=1;i<=n;i++)
    {
        Add(rk[i],1);
        ans+=(i-Sum(rk[i]));
    }
    printf("%lld\n",ans);
    return 0;
}
