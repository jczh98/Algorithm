#include <cstdio>
#include <iostream>
#include <cstring>
int n,m,notallow[10000],root=0;
int main()
{
    memset(notallow,0,sizeof(notallow));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);notallow[u]=notallow[v]=1;
    }
    printf("%d\n",n-1);
    for(int i=1;i<=n;i++)if(!notallow[i])
    {
        root=i;break;
    }
    for(int i=1;i<=n;i++)
    {
        if(i!=root)printf("%d %d\n",root,i);
    }
    return 0;
}
