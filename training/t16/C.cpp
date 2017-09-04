#include <bits/stdc++.h>
using namespace std;
int t,n,pi[1100],vis[1100],ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&pi[i]);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                ans++;
                vis[i]=1;
                int cur=pi[i];
                while(cur!=i)
                {
                    vis[cur]=1;
                    cur=pi[cur];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
