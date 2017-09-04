#include <bits/stdc++.h>
using namespace std;
const int MN=500500;
int n,k,a[MN],num[MN][10],f[MN][10];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=k;i++)
    {
        for(int j=0;i+j<=n;j+=k)
        {
            if(a[i+j]>0)num[i][1]++;
            else num[i][0]++;
        }
    }
    f[1][0]=num[1][0];f[1][1]=num[1][1];
    for(int i=2;i<=k;i++)
    {
        f[i][1]=min(f[i-1][1]+num[i][0],f[i-1][0]+num[i][1]);
        f[i][0]=min(f[i-1][0]+num[i][0],f[i-1][1]+num[i][1]);
    }
    printf("%d\n",f[k][0]);
    return 0;
}
