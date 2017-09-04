#include <bits/stdc++.h>
#define MN 32*100000
using namespace std;
int ch[MN][2],val[MN];
int cnt=1;
void Insert(int k)
{
    int u=0;
    for(int i=31;i>=0;i--)
    {
        int v=((k>>i)&1);
        if(!ch[u][v])
        {
            memset(ch[cnt],0,sizeof(ch[cnt]));
            val[cnt]=0;
            ch[u][v]=cnt++;
        }
        u=ch[u][v];
    }
    val[u]=k;
}
int Query(int k)
{
    int u=0;
    for(int i=31;i>=0;i--)
    {
        int v=((k>>i)&1);
        if(ch[u][v^1])v^=1;
        u=ch[u][v];
    }
    return val[u]^k;
}
int t,n,a[100100],ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        memset(ch[0],0,sizeof(ch[0]));cnt=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            a[i]^=a[i-1];
        }
        for(int i=0;i<n;i++)
        {
            Insert(a[i]);
            ans=max(ans,Query(a[i+1]));
        }
        printf("%d\n",ans);
    }
    return 0;
}


