#include <bits/stdc++.h>
using namespace std;
int n,m,ans=100000,G[500][500],b[500],cnt[500]={0},cur_max,cur_i,vis[500]={0};
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
    for(int i=1;i<=m;i++)b[i]=i;
    for(int i=1;i<=n;i++)cnt[G[i][1]]++;
    for(int i=1;i<=m;i++)
    {
        if(cur_max<cnt[i])
        {
            cur_max=cnt[i];cur_i=i;
        }
    }
    vis[cur_i]=1;
    //cout<<cur_i<<" "<<cur_max<<endl;
    while(cur_max!=0)
    {
        ans=min(cur_max,ans);
        cur_max=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(!vis[G[i][j]])
                {
                    cnt[G[i][j]]++;
                    break;
                }
            }
        }
        //for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";cout<<endl;
        for(int i=1;i<=m;i++)
        {
            if(cur_max<cnt[i]&&!vis[i])
            {
                cur_max=cnt[i];
                cur_i=i;
            }
        }
        vis[cur_i]=1;
    }
    printf("%d\n",ans);
    return 0;
}
