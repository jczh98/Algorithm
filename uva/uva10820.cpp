#include <cstdio>
#include <iostream>
#include <cstring>
#define MN 500050
typedef long long LL;
LL ans;
int n,phi[MN],vis[MN],prime[MN],tot;
void Shaker()
{
    memset(vis,0,sizeof(vis));
    phi[1]=1;tot=0;
    for(int i=2;i<=MN;i++)
    {
        if(!vis[i])
        {
            prime[tot++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<tot&&i*prime[j]<MN;j++)
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }else
            {
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
}
int main()
{
    Shaker();
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;ans=0;
        for(int i=2;i<=n;i++)
        {
            ans+=(long long)phi[i];
        }
        ans=ans*2+1;
        printf("%lld\n",ans);
    }
    return 0;
}
