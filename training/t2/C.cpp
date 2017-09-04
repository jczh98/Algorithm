#include <bits/stdc++.h>
#define MN 110
using namespace std;
char mp[MN][MN];
int t,n,sum,vis[100],ans,mini,mx;
int GetCh(char ch)
{
    if(isalpha(ch))return ch-'a';
    else if(ch=='.') return 'z'-'a'+1;
    else if(ch=='#') return 'z'-'a'+2;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%s",mp[i]);
        for(int i=0;i<n/2;i++)
        {
            for(int j=i+1;j<n/2;j++)
            {
                memset(vis,0,sizeof(vis));
                vis[GetCh(mp[i][j])]++;
                vis[GetCh(mp[n-1-i][j])]++;
                vis[GetCh(mp[i][n-1-j])]++;
                vis[GetCh(mp[n-1-i][n-1-j])]++;
                vis[GetCh(mp[j][i])]++;
                vis[GetCh(mp[n-1-j][i])]++;
                vis[GetCh(mp[j][n-1-i])]++;
                vis[GetCh(mp[n-1-j][n-1-i])]++;
                sum=0;
                for(int k=0;k<=27;k++)if(vis[k]>0)sum++;
                if(sum>1)
                {
                    mx=0;
                    for(int k=0;k<=27;k++)if(vis[k]>0)mx=max(vis[k],mx);
                    ans+=(8-mx);
                }
            }
        }
        for(int i=0;i<n/2;i++)
        {
            memset(vis,0,sizeof(vis));
            vis[GetCh(mp[i][i])]++;
            vis[GetCh(mp[n-1-i][n-1-i])]++;
            vis[GetCh(mp[n-1-i][i])]++;
            vis[GetCh(mp[i][n-1-i])]++;
            sum=0;
            for(int k=0;k<=27;k++)if(vis[k]>0)sum++;
            if(sum>1)
            {
                mx=0;
                for(int k=0;k<=27;k++)if(vis[k]>0)mx=max(vis[k],mx);
                ans+=(4-mx);
            }
        }
        int j=n/2;
        for(int i=0;i<n/2;i++)
        {
            memset(vis,0,sizeof(vis));
            vis[GetCh(mp[i][j])]++;
            vis[GetCh(mp[n-1-i][j])]++;
            vis[GetCh(mp[j][i])]++;
            vis[GetCh(mp[j][n-1-i])]++;
            sum=0;
            for(int k=0;k<=27;k++)if(vis[k]>0)sum++;
            if(sum>1)
            {
                mx=0;
                for(int k=0;k<=27;k++)if(vis[k]>0)mx=max(vis[k],mx);
                ans+=(4-mx);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
