#include <bits/stdc++.h>
#define MN 1100
using namespace std;
int n,x[MN],y[MN],r[MN],color[MN];
int Gcd(int a,int b)
{
    if(a<b)swap(a,b);
    return b==0?a:Gcd(b,a%b);
}
struct Edge
{
    int to,nxt,c;
}e[MN*MN];
int cnt=1,head[MN];
void AddEdge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].nxt=head[u];
    head[u]=cnt++;
}
bool Dfs(int x,int c)
{
    color[x]=c;
    for(int i=head[x];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(color[v]==c)return false;
        if(!color[v]&&!Dfs(v,-c))return false;
    }
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&x[i],&y[i],&r[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])==(r[i]+r[j])*(r[i]+r[j]))
            {
                AddEdge(i,j);
                AddEdge(j,i);
            }
        }
    }
    if(!Dfs(1,1)) printf("The input gear cannot move.\n");
    else if(!color[n]) printf("The input gear is not connected to the output gear.\n");
    else
    {
        int g=Gcd(r[1],r[n]);
        if(color[1]!=color[n])printf("-");
        printf("%d:%d\n",r[1]/g,r[n]/g);
    }
    return 0;
}
