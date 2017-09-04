#include <bits/stdc++.h>
using namespace std;
int n,m,a[200200],cnt[200200],res,vis[200200];
int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&m);res=n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cnt[a[i]]++;
        int pos=a[i]-cnt[a[i]];
        if(pos>=0)
        {
            if(!vis[pos])res--;
            vis[pos]++;
        }
    }
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int pos=a[x]-cnt[a[x]];
        if(pos>=0)
        {
            if(vis[pos]==1)res++;
            vis[pos]--;
        }
        cnt[a[x]]--;
        a[x]=y;
        cnt[y]++;
        pos=a[x]-cnt[a[x]];
        if(pos>=0)
        {
            if(!vis[pos])res--;
            vis[pos]++;
        }
        printf("%d\n",res);
    }
    return 0;
}
