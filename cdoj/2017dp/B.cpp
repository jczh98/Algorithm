#include <bits/stdc++.h>
using namespace std;
int x,y,z,p,n,a[30][30][30],d[1<<21];
int dp(int s)
{
    if(d[s]!=-1)return d[s];
    int i;
    for(i=0;i<n-2;i++)if(s&(1<<i))break;
    for(int j=i+1;j<n-1;j++)if(s&(1<<j))
        for(int k=j+1;k<n;k++)if(s&(1<<k))
            d[s]=max(d[s],dp(s^(1<<i)^(1<<j)^(1<<k))+a[i][j][k]);
    return d[s];
}
int main()
{
    memset(d,-1,sizeof(d));
    scanf("%d",&n);
    for(int i=1;i<=n*(n-1)*(n-2)/6;i++)scanf("%d%d%d%d",&x,&y,&z,&p),a[x-1][y-1][z-1]=p;
    d[0]=0;
    dp((1<<n)-1);
    printf("%d\n",d[(1<<n)-1]);
    return 0;
}
