#include <bits/stdc++.h>
#define MN 1001000
using namespace std;
typedef long long LL;
int n,m[MN],v[MN],w[MN];
LL f[MN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        m[x]=y;w[x]=z;
    }
    for(int i=1000000;i>=1;i--)
    {
        if(i+w[i]>1000000)f[i]=max(f[i+1],(LL)m[i]);
        else f[i]=max(f[i+1],f[i+w[i]]+m[i]);
    }
    cout<<f[1]<<endl;
    return 0;
}
