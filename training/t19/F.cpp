#include <bits/stdc++.h>
#define MAXN 300000+10
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
int t,n,query,p[MAXN],id;
int L[MAXN],R[MAXN],dep[MAXN],tot=0;
vector<int> edge[MAXN];
void Dfs(int u,int fa,int d)
{
    L[u]=++tot;
    dep[u]=d;
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        if(v==fa)continue;
        Dfs(v,u,d+1);
    }
    R[u]=tot;
}
struct Fenwick
{
    LL C[MAXN];
    int Lowbit(int x)
    {
        return x&(-x);
    }
    void Add(int x,LL d)
    {
        while(x<=n)
        {
            C[x]+=d;
            x+=Lowbit(x);
        }
    }
    LL Sum(int x)
    {
        LL sum=0;
        while(x)
        {
            sum+=C[x];
            x-=Lowbit(x);
        }
        return sum;
    }
}xval,kval;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        scanf("%d",&n);
        for(int i=2;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            edge[x].push_back(i);
        }
        Dfs(1,-1,0);
        //for(int i=1;i<=n;i++)cout<<L[i]<<" ";cout<<endl;
        //for(int i=1;i<=n;i++)cout<<R[i]<<" ";cout<<endl;
        scanf("%d",&query);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&id);
            if(id==1)
            {
                int v,x,k;
                scanf("%d%d%d",&v,&x,&k);
                xval.Add(L[v],(x+dep[v]*k%MOD)%MOD);
                xval.Add(R[v]+1,-(x+dep[v]*k%MOD)%MOD);
                kval.Add(L[v],k);
                kval.Add(R[v]+1,-k);
            }else
            {
                int v;
                scanf("%d",&v);
                LL x=xval.Sum(L[v]);
                LL k=kval.Sum(L[v]);
                cout<<(x-(LL)dep[v]*k+MOD)%MOD<<endl;
            }
        }
    }
    return 0;
}
