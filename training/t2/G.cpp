#include <bits/stdc++.h>
#define MN 11000
using namespace std;
int n,t,v[MN][2],sum[MN],ans;
int Dfs(int x)
{
    if(sum[x]==0)
    {
        return 1;
    }else if(sum[x]==1)
    {
        return Dfs(v[x][0]);
    }else
    {
        int ls=v[x][0],rs=v[x][1];
        int l=Dfs(ls);
        int r=Dfs(rs);
        return max(min(l,r)+1,max(l,r));
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        memset(v,0,sizeof(v));
        for(int i=1;i<n;i++)
        {
            scanf("%d",&t);
            if(!v[t][0])v[t][0]=i+1;
            else v[t][1]=i+1;
            sum[t]++;
        }
        ans=Dfs(1);
        printf("%d\n",ans);
    }
    return 0;
}
