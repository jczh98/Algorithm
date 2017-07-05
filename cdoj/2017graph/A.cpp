#include <bits/stdc++.h>
#define MN 1010
using namespace std;
int n,m,fa[MN],ans=INT_MAX;
struct Edge
{
    int u,v,w;
    bool operator<(const Edge& rhs)const{return w<rhs.w;}
}e[MN];
int Find(int x){return fa[x]==x?fa[x]:fa[x]=Find(fa[x]);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    sort(e+1,e+1+m);
    /*for(int i=1;i<=m;i++)
    {
        cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<endl;
    }*/
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<MN;j++)fa[j]=j;
        for(int j=i;j<=m;j++)
        {
            int a=Find(e[j].u),b=Find(e[j].v);
            if(a!=b){fa[a]=b;}
            if(Find(1)==Find(n))
            {
                //cout<<j<<" "<<i<<endl;
                ans=min(ans,e[j].w-e[i].w);
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
