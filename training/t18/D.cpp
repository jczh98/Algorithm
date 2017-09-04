#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,p,c,son[100100];
LL leaf_time[100100],query;
struct Edge
{
    int to,nxt,c;
}edge[101000];
int cnt,head[100100];
vector<LL> finder;
void AddEdge(int u,int v,int w)
{
    edge[cnt].to=v;
    edge[cnt].c=w;
    edge[cnt].nxt=head[u];
    head[u]=cnt++;
}
void Dfs(int u)
{
    if(son[u]==0)
    {
        finder.push_back(leaf_time[u]);
        return;
    }
    LL min_c=INT_MAX;
    for(int i=head[u];i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        min_c=min(min_c,(LL)edge[i].c);
    }
    //cout<<min_c<<endl;
    for(int i=head[u];i;i=edge[i].nxt)
    {
        int v=edge[i].to,w=edge[i].c;
        leaf_time[v]=leaf_time[u]+min_c+2LL*(w-min_c);
        Dfs(v);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cnt=1;
        memset(head,0,sizeof(head));
        memset(leaf_time,0,sizeof(leaf_time));
        memset(son,0,sizeof(son));
        finder.clear();
        scanf("%d",&n);
        for(int i=2;i<=n;i++)
        {
            scanf("%d%d",&p,&c);
            AddEdge(p,i,c);
            son[p]++;
        }
        Dfs(1);
        sort(finder.begin(),finder.end());
        int q;
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            cin>>query;
            int p=upper_bound(finder.begin(),finder.end(),query)-finder.begin();
            cout<<p<<endl;
        }
    }
    return 0;
}
