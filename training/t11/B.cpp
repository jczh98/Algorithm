#include <bits/stdc++.h>
#define N 4010
#define M 5050
using namespace std;
int n,a,b,cnt=0,G[N],ans[N];
void Euler(int u)
{
    for(int i=4*u-3;i<=4*u;i++)
    {
        if(G[i])
        {
            int v=G[i];
            G[v]=G[i]=0;
            Euler((v+3)/4);
            ans[cnt++]=v;
            ans[cnt++]=i;
        }
    }
}
int main()
{
    freopen("courier.in","r",stdin);
    freopen("courier.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        scanf("%d%d",&a,&b);
        G[a]=b;
        G[b]=a;
    }
    Euler(1);
    if(cnt!=n*4)
    {
        printf("No\n");
    }else
    {
        printf("Yes\n");
        for(int i=cnt-1;i>0;i--)
        {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[0]);
    }
    return 0;
}
