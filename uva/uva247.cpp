#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int n,m,G[50][50],d[50][50],vis[50];
map<string,int> num;
map<int,string> mapping;
void Dfs(int u)
{
    vis[u]=1;
    for(int i=1;i<=n;i++)
        if(G[u][i]==1&&G[i][u]==1)if(!vis[i])cout<<", "<<mapping[i],Dfs(i);
}
int main()
{
    int kase=1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        num.clear();mapping.clear();
        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));
        if(n==0&&m==0)break;
        if(kase>1)printf("\n");
        printf("Calling circles for data set %d:\n",kase++);
        int cnt=1;memset(G,0,sizeof(G));
        for(int i=1;i<=m;i++)
        {
            char s1[50],s2[50];
            scanf("%s%s",s1,s2);
            if(num.count(s1)==0)mapping[cnt]=s1,num[s1]=cnt++;
            if(num.count(s2)==0)mapping[cnt]=s2,num[s2]=cnt++;
            int x=num[s1],y=num[s2];
            G[x][y]=1;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    G[i][j]=(G[i][j]||(G[i][k]&&G[k][j]));
        for(int i=1;i<=n;i++)
            if(!vis[i])
            {
                cout<<mapping[i];
                Dfs(i);
                printf("\n");
            }
    }
    return 0;
}
