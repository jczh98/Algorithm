#include <bits/stdc++.h>
#define MN 10010
using namespace std;
//int sg[7]={0,0,1,1,0,2,1};
int s[MN],k,m,t,h[MN],vis[MN],sg[MN];
int main()
{
    scanf("%d",&k);
    for(int i=1;i<=k;i++)scanf("%d",&s[i]);
    for(int i=1;i<=MN;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=k;j++)if(i-s[j]>=0)vis[sg[i-s[j]]]=1;
        for(int j=0;j<=MN;j++)if(!vis[j]){sg[i]=j;break;}
    }
    //for(int i=0;i<=100;i++)printf("%d ",sg[i]);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&t);
        for(int i=1;i<=t;i++)
        {
            scanf("%d",&h[i]);
        }
        int ans=sg[h[1]];
        for(int i=2;i<=t;i++)
        {
            ans^=sg[h[i]];
        }
        printf("%s\n",ans==0?"lose!":"win!");
    }
    return 0;
}
