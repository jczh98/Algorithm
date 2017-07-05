#include <bits/stdc++.h>
#define M 100100
#define N 100100
using namespace std;
int n,m,x,y,dis1[N],dis2[N],vis1[N],vis2[N],ans=0;
struct Edge
{
    int to,nxt;
}e[M],e_scc[M],e_inv[M];
int cnt=1,head[N];
void Add(int u,int v)
{
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}
int cnt2=1,head2[N];
void Add2(int u,int v)
{
    e_scc[cnt2].to=v;
    e_scc[cnt2].nxt=head2[u];
    head2[u]=cnt2++;
}
int cnt3=1,head3[N];
void Add3(int u,int v)
{
    e_inv[cnt3].to=v;
    e_inv[cnt3].nxt=head3[u];
    head3[u]=cnt3++;
}
int dfs_ind=1,dfn[N],low[N],sccno[N],scc_cnt=0,w[N];
stack<int> st;
void Tarjan(int u)
{
    dfn[u]=low[u]=dfs_ind++;
    st.push(u);
    for(int i=head[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(!sccno[v])
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u])
    {
        scc_cnt++;
        while(true)
        {
            int x=st.top();st.pop();
            sccno[x]=scc_cnt;
            w[scc_cnt]++;
            if(x==u)break;
        }
    }
}
void DAG()
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(sccno,0,sizeof(sccno));
    memset(w,0,sizeof(w));
    memset(head2,0,sizeof(head2));
    memset(head3,0,sizeof(head3));
    for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
    for(int i=1;i<=n;i++)
    {
        for(int j=head[i];j;j=e[j].nxt)
        {
            int v=e[j].to;
            if(sccno[i]!=sccno[v])
            {
                Add2(sccno[i],sccno[v]);Add3(sccno[v],sccno[i]);
            }
        }
    }
}
int Spfa1(int s)
{
    memset(vis1,0,sizeof(vis1));
    dis1[s]=w[s];vis1[s]=1;
    queue<int> pq;
    pq.push(s);
    while(!pq.empty())
    {
        int now=pq.front();pq.pop();vis1[now]=0;
        for(int i=head2[now];i;i=e_scc[i].nxt)
        {
            int v=e_scc[i].to;
            if(dis1[v]<dis1[now]+w[v])
            {
                dis1[v]=dis1[now]+w[v];
                if(!vis1[v])pq.push(v),vis1[v]=1;
            }
        }
    }
}
int Spfa2(int s)
{
    memset(vis2,0,sizeof(vis2));
    dis2[s]=w[s];vis2[s]=1;
    queue<int> pq;
    pq.push(s);
    while(!pq.empty())
    {
        int now=pq.front();pq.pop();vis2[now]=0;
        for(int i=head3[now];i;i=e_inv[i].nxt)
        {
            int v=e_inv[i].to;
            if(dis2[v]<dis2[now]+w[v])
            {
                dis2[v]=dis2[now]+w[v];
                if(!vis2[v])pq.push(v),vis2[v]=1;
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        Add(x,y);
    }
    DAG();
    Spfa1(sccno[1]);
    Spfa2(sccno[1]);
    for(int i=1;i<=scc_cnt;i++)
    {
        for(int j=head2[i];j;j=e_scc[j].nxt)
        {
            int v=e_scc[j].to;
            if(dis1[v]&&dis2[i])ans=max(ans,dis1[v]+dis2[i]-w[sccno[1]]);
        }
    }
    if(scc_cnt==1)printf("%d\n",w[1]);
    else printf("%d\n",ans);
    return 0;
}
