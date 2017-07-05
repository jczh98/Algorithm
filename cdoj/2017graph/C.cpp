#include <bits/stdc++.h>
#define MN 200200
using namespace std;
int n,cntrow[MN],cntcol[MN],mxrow=0,mxcol=0,vis[MN],color[MN];
struct Node
{
    int x,y,pos,color;
}node[MN];
struct Edge
{
    int to,next;
}edge[2*MN];
int head[MN],cnt=1;
int cmp1(Node x,Node y)
{
    if(x.x!=y.x)return x.x<y.x;
    else return x.y<y.y;
}
int cmp2(Node x,Node y)
{
    if(x.y!=y.y)return x.y<y.y;
    else return x.x<y.x;
}
void AddEdge(int u,int v)
{
    edge[cnt].to=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void Add(int u,int v)
{
    AddEdge(u,v);AddEdge(v,u);
}
void Dfs(int x,int dep)
{
    if(vis[x])return;vis[x]=1;
    if(dep)color[x]=1;
    for(int i=head[x];i;i=edge[i].next)
    {
        int v=edge[i].to;
        Dfs(v,dep^1);
    }
}
int main()
{
    memset(color,0,sizeof(color));
    memset(vis,0,sizeof(vis));
    memset(head,0,sizeof(head));
    memset(cntrow,0,sizeof(cntrow));
    memset(cntcol,0,sizeof(cntcol));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",&node[i].x,&node[i].y),node[i].pos=i,cntrow[node[i].x]++,cntcol[node[i].y]++,mxrow=max(mxrow,node[i].x),mxcol=max(mxcol,node[i].y);
    sort(node+1,node+1+n,cmp1);
    for(int i=1;i<=n;i+=cntrow[node[i].x])
    {
        for(int j=0;j<cntrow[node[i].x]-1;j+=2)
        {
            Add(node[i+j].pos,node[i+j+1].pos);
        }
    }
    sort(node+1,node+1+n,cmp2);
    for(int i=1;i<=n;i+=cntcol[node[i].y])
    {
        for(int j=0;j<cntcol[node[i].y]-1;j+=2)
        {
            Add(node[i+j].pos,node[i+j+1].pos);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            Dfs(i,0);
        }
    }
    for(int i=1;i<=n;i++)
    {
        //printf("%d",color[i]);
        if(color[i])printf("r");
        else printf("b");
    }printf("\n");
    return 0;
}
