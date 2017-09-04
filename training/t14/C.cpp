#include <bits/stdc++.h>
#define MAXM 5005000
#define MAXN 5005000
using namespace std;
int c,l,vis[MAXN],son[MAXN],sz=0,ans=0,dp[MAXN],Max=0,connected=0;
vector<int> diameter;
struct Edge
{
    int to,nxt,w;
}edge[MAXM];
int cnt=1,head[MAXN];
void AddEdge(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].nxt=head[u];
    edge[cnt].w=w;
    head[u]=cnt++;
}
void Dfs(int s)
{
    vis[s]=1;
    for(int i=head[s];i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(!vis[v])
        {
            Dfs(v);
            Max=max(Max,dp[s]+dp[v]+1);
            dp[s]=max(dp[s],dp[v]+1);
        }
    }
}
int main()
{
    scanf("%d%d",&c,&l);
    for(int i=1;i<=l;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);a++;b++;
        AddEdge(a,b,1);AddEdge(b,a,1);
    }
    for(int i=1;i<=c;i++)
    {
        if(!vis[i])
        {
            connected++;
            //memset(dp,0,sizeof(dp));
            Max=0;
            Dfs(i);
            diameter.push_back(Max);
        }
    }
    sort(diameter.begin(),diameter.end());
    if(connected==1)
    {
        cout<<diameter[0]<<endl;
    }else if(connected==2)
    {
        cout<<max(diameter[1],(diameter[0]+1)/2+(diameter[1]+1)/2+1)<<endl;
    }else if(connected>=3)
    {
        int sz=diameter.size();
        ans=max((diameter[sz-1]+1)/2+1+(diameter[sz-2]+1)/2,diameter[sz-1]);
        ans=max(ans,(diameter[sz-3]+1)/2+2+(diameter[sz-2]+1)/2);
        cout<<ans<<endl;
    }
    return 0;
}
