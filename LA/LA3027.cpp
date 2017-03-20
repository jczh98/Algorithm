#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int t,fa[100000],d[100000];
int Find(int x)
{
    if(fa[x]==x)return x;
    int root=Find(fa[x]);
    d[x]+=d[fa[x]];
    fa[x]=root;
    return root;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<100000;i++)fa[i]=i,d[i]=0;
        char c[10];int u,v;
        while(1)
        {
            scanf("%s",&c);
            if(c[0]=='O')break;
            if(c[0]=='I')
            {
                scanf("%d%d",&u,&v);
                fa[u]=v;d[u]=abs(u-v)%1000;
            }else if(c[0]=='E')
            {
                scanf("%d",&u);
                Find(u);printf("%d\n",d[u]);
            }
        }
    }
    return 0;
}
