#include <bits/stdc++.h>
#define MN 400000
using namespace std;
int n,t,vis[MN],ans[MN];
int Dfs(int x,int k)
{
    if(vis[x])return 0;
    if(k==t)return 1;
    ans[k]=x&1;vis[x]=1;
    if(Dfs((x<<1)&(t-1),k+1))return 1;
	if(Dfs((x<<1|1)&(t-1),k+1))return 1;
	vis[x]=0;
	return 0;
}
int main()
{
    scanf("%d",&n);t=(1<<n);
    Dfs(0,1);
    if(n==1)
    {
        printf("01\n");
        return 0;
    }
    for(int i=1;i<n;i++)printf("0");
	for(int i=1;i<=t-n+1;i++)printf("%d",ans[i]);
	printf("\n");
	return 0;
}
