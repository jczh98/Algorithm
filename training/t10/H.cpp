#include <bits/stdc++.h>
#define N 100100
using namespace std;
typedef long long LL;
int n,m,d,cnt=1,fake_rk[N],indeg[N],rk[N],dp[N];
map<LL,int> ids;
map<int,LL> name;
vector<int> G[N],pos;
void TopoSort()
{
    queue<int> que;
    for(int i=1;i<=n;i++)if(!indeg[i])que.push(i);
    int tot=1;
    while(!que.empty())
    {
        int u=que.front();que.pop();rk[u]=tot++;
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            indeg[v]--;
            if(!indeg[v])que.push(v);
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=m;i++)
    {
        LL a,b;
        scanf("%lld%lld",&a,&b);
        if(!ids.count(a))ids[a]=cnt,name[cnt]=a,cnt++;
        if(!ids.count(b))ids[b]=cnt,name[cnt]=b,cnt++;
        G[ids[a]].push_back(ids[b]);
        indeg[ids[b]]++;
    }

    TopoSort();
    for(int i=1;i<=n;i++)
    {
        LL a;
        scanf("%lld",&a);
        if(ids.count(a))pos.push_back(rk[ids[a]]);
    }
    if(pos.size()==0)
    {
        printf("%d\n",2*n);
    }else
    {
        int now=1;dp[1]=pos[0];
        for(int i=1;i<pos.size();i++)
        {
            if(pos[i]>dp[now])dp[++now]=pos[i];
            else
            {
                int j=lower_bound(dp+1,dp+now,pos[i])-dp;
                dp[j]=pos[i];
            }
        }
        printf("%d\n",2*(n-now));
    }
    return 0;
}
