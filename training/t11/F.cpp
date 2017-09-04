#include <bits/stdc++.h>
#define N 100100
using namespace std;
vector<int> factor[N];
int n,a,b,x,i,j,by,vis[N],ans=0;
int main()
{
    //freopen("game.in","r",stdin);
    //freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j*j<=i;j++)
        {
            if(i%j==0)
            {
                factor[i].push_back(j);
                if(j*j!=i)factor[i].push_back(i/j);
            }
        }
        sort(factor[i].begin(),factor[i].end(),greater<int>());
    }
    for(a=1;a<=n;a++)
    {
        for(x=1;x*a<=n;x++)
        {
            by=n-x*a;
            for(j=0;j<factor[by].size();j++)
            {
                b=factor[by][j];
                if(b<=a)break;
                if(vis[b]!=a)
                {
                    ans++;
                    vis[b]=a;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
