#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#define MN 10010
using namespace std;
typedef long long LL;
int n,m,ans;
struct Edge
{
    int u,v,w;
}e[MN];
int fa[MN];
int Find(int x){return x==fa[x]?x:fa[x]=Find(fa[x]);}
int cmp(Edge a,Edge b) {return a.w<b.w;}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sort(e+1,e+1+m,cmp);
        int tot;ans=INT_MAX;
        for(int i=1;i<=m;i++)
        {
            for(int k=0;k<=n;k++)fa[k]=k;tot=0;
            for(int j=i;j<=m;j++)
            {
                int x=Find(e[j].u),y=Find(e[j].v);
                if(x!=y)tot++,fa[x]=y;
                if(tot==n-1)
                {
                    ans=min(ans,e[j].w-e[i].w);
                    break;
                }
            }
        }
        if(ans==INT_MAX)printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}
