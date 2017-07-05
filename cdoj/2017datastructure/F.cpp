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
int n,a,m;
int main()
{
    scanf("%d",&n);
    memset(ch[0],0,sizeof(ch[0]));cnt=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        Insert(a);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&a);
        printf("%d\n",Query(a));
    }
    return 0;
}
