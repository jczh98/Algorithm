#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i,x,y)for(int i=x;i<y+1;i++)
#define fs(i,x,y)for(int i=x;i>y-1;i--)
#define all(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
using namespace std;
typedef long long ll;
ll n,m,dp[100010],d[100010],ans,vis[100010];
vector<ll>g[100010];
typedef struct node
{
    ll val,id;
};
node mes[100010];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int main()
{
    scanf("%lld%lld",&n,&m);
    ff(i,1,m)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        d[a]++;
        d[b]++;
    }
    ff(i,0,n-1)
    {
        mes[i].val=d[i];
        mes[i].id=i;
    }
    sort(mes,mes+n,cmp);
    ff(i,0,n-1)
    {
        int sz=g[mes[i].id].size();
        vis[mes[i].id]=1;
        ff(j,0,sz-1)
        {
            if(vis[g[mes[i].id][j]]||d[mes[i].id]==d[g[mes[i].id][j]])continue;
            dp[g[mes[i].id][j]]=max( dp[g[mes[i].id][j]],dp[mes[i].id]+1);
            ans=max(ans, dp[g[mes[i].id][j]]);
        }
    }
    cout<<ans+1<<endl;
    return 0;
}