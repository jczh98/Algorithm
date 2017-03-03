#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1000
using namespace std;

int n,vis[N],ans[N],kase=0;

int check[N],prime[N],cnt;
void Sieve()
{
    memset(check,0,sizeof(check));
    cnt=0;check[0]=1;
    for(int i=2;i<N;i++)
    {
        if(!check[i])prime[cnt++]=i;
        for(int j=0;j<cnt&&i*prime[j]<N;j++)
        {
            check[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}

void Backtrack(int cur)
{
    if(cur==n&&!check[ans[n-1]+ans[0]])
    {
        for(int i=0;i<n;i++)
        {
            if(i!=0)printf(" ");printf("%d",ans[i]);
        }
        printf("\n");
        return;
    }else for(int i=2;i<=n;i++)
    {
        if(!vis[i]&&!check[i+ans[cur-1]])
        {
            vis[i]=1;
            ans[cur]=i;
            Backtrack(cur+1);
            vis[i]=0;
        }
    }
    return;
}

int main()
{
    Sieve();
    while(scanf("%d",&n)!=EOF)
    {
        if(kase>0)printf("\n");
        printf("Case %d:\n",++kase);
        memset(vis,0,sizeof(vis));
        ans[0]=1;
        Backtrack(1);
    }
    return 0;
}
