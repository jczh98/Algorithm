#include <bits/stdc++.h>
#define MN 600600
using namespace std;
int n,k,vis[MN],ind[MN],num[MN];
int main()
{
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&num[i]);ind[num[i]]=i;vis[num[i]]=1;
    }
    sort(num+1,num+1+k);
    for(int i=1;i<=k;i++)
    {
        for(int j=2;j*num[i]<=n;j++)
        {
            if(vis[j*num[i]])
            {
                printf("%d %d\n",ind[j*num[i]],ind[num[i]]);
                return 0;
            }
        }
    }
    printf("0 0\n");
    return 0;
}
