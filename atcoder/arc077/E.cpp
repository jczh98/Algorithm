#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MN=100100;
int n,m,a[MN];
LL k[2*MN]={0},b[2*MN]={0},sum=0,mx=0;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u=a[i],v=a[i+1];
        if(u>v)v+=m;
        sum+=(v-u);
        k[u+1]++;k[v+1]--;
        b[u+1]+=(a[i]+1);b[v+1]-=(a[i]+1);
    }
    for(int i=2;i<=2*m;i++)k[i]+=k[i-1],b[i]+=b[i-1];
    for(int i=1;i<=m;i++)
    {
        mx=max(mx,k[i]*i+k[i+m]*(i+m)-b[i]-b[i+m]);
    }
    printf("%lld\n",sum-mx);
    return 0;
}
