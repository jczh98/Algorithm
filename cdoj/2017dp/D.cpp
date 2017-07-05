#include <bits/stdc++.h>
#define N 20010
using namespace std;
int n,k,t[N],a[N],b[N],f[N];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&t[i],&a[i],&b[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(t[i]==1)
        {
            for(int j=b[i];j<=k;j++)
            {
                f[j]=max(f[j],f[j-b[i]]+a[i]);
            }
        }else if(t[i]==2)
        {
            for(int j=k;j>=b[i];j--)
            {
                f[j]=max(f[j],f[j-b[i]]+a[i]);
            }
        }
    }
    printf("%d\n",f[k]);
    return 0;
}
