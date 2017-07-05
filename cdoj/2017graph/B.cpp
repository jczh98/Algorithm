#include <bits/stdc++.h>
#define MN 2020
#define inf INT_MAX
using namespace std;
typedef pair<int,int> pii;
int n,a[MN],q,m,minv=inf,d[50005],vis[50005];
priority_queue<pii,vector<pii>,greater<pii> > que;
int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),minv=min(minv,a[i]);
    d[0]=0;for(int i=1;i<minv;i++)d[i]=inf;
    que.push(make_pair(d[0],0));
    while(!que.empty())
    {
        int u=que.top().second;que.pop();
        if(vis[u])continue;vis[u]=1;
        for(int i=1;i<=n;i++)
        {
            int v=(u+a[i])%minv;
            if(d[u]+a[i]<d[v])
            {
                d[v]=d[u]+a[i];
                que.push(make_pair(d[v],v));
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(d[a[i]]+a[j]<d[(a[i]+a[j])%minv])
            {
                d[(a[i]+a[j])%minv]=d[a[i]]+a[j];
            }
        }
    }*/
    //for(int i=0;i<minv;i++)printf("%d ",d[i]);printf("\n");
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&m);
        if(m<d[m%minv])printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

