#include <cstdio>
#include <cstring>
#define MN 100100
int n,prime[MN],vis[MN],cnt=0,ans[MN];
void Shaker()
{
    memset(vis,0,sizeof(vis));vis[1]=0;
    for(int i=2;i<=MN;i++)
    {
        if(!vis[i])prime[cnt++]=i;
        for(int j=0;j<cnt;j++)
        {
            if(i*prime[j]>MN)break;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main()
{
    Shaker();
    scanf("%d",&n);
    int k=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i+1]==0)ans[i]=1;
        else ans[i]=2;
    }
    if(n==1||n==2)printf("1\n");
    else printf("2\n");
    for(int i=1;i<n;i++)printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}
