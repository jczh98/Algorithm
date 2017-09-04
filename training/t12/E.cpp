#include <bits/stdc++.h>
#define MAXN 500500
using namespace std;
struct Triple
{
    int x,y,z;
};
unordered_map<int,int> ids;
unordered_map<int,int> shadow_ids;
int CalId(int x,int y,int z)
{
    return x*1000000+y*1000+z;
}
int CalId(int x,int y)
{
    return x*1000000+y*1000;
}
Triple N[2*MAXN];
vector<int> G[2*MAXN];
int k,cnt,vis[2*MAXN];
bool Dfs(int u,int fa)
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!vis[v])
        {
            if(Dfs(v,u))return true;
        }else if(v!=fa)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d",&k);
    cnt=1;
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d%d%d%d%d",&N[i<<1].x,&N[i<<1].y,&N[i<<1].z,&N[i<<1|1].x,&N[i<<1|1].y,&N[i<<1|1].z);
        int tri1=CalId(N[i<<1].x,N[i<<1].y,N[i<<1].z),tri2=CalId(N[i<<1|1].x,N[i<<1|1].y,N[i<<1|1].z);
        if(ids.find(tri1)==ids.end()) ids[tri1]=cnt++;
        if(ids.find(tri2)==ids.end()) ids[tri2]=cnt++;
        if(ids[tri1]!=ids[tri2])
        {
            G[ids[tri1]].push_back(ids[tri2]);
            G[ids[tri2]].push_back(ids[tri1]);
        }
    }
    for(int i=1;i<cnt;i++)
    {
        sort(G[i].begin(),G[i].end());
        G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
    }
    memset(vis,0,sizeof(vis));
    if(Dfs(1,-1))
    {
        printf("True closed chains\n");
    }else printf("No true closed chains\n");

    for(int i=1;i<cnt;i++)
    {
        G[i].clear();
    }
    cnt=1;
    for(int i=1;i<=k;i++)
    {
        int s1=CalId(N[i<<1].x,N[i<<1].y),s2=CalId(N[i<<1|1].x,N[i<<1|1].y);
        if(shadow_ids.find(s1)==shadow_ids.end())shadow_ids[s1]=cnt++;
        if(shadow_ids.find(s2)==shadow_ids.end())shadow_ids[s2]=cnt++;
        if(shadow_ids[s1]!=shadow_ids[s2])
        {
            G[shadow_ids[s1]].push_back(shadow_ids[s2]);
            G[shadow_ids[s2]].push_back(shadow_ids[s1]);
        }
    }
    for(int i=1;i<cnt;i++)
    {
        sort(G[i].begin(),G[i].end());
        G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());
    }
    memset(vis,0,sizeof(vis));
    if(Dfs(1,-1))
    {
        printf("Floor closed chains\n");
    }else printf("No floor closed chains\n");
    return 0;
}
