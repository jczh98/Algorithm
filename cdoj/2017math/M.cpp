#include <bits/stdc++.h>
#define MN 1000100
using namespace std;
typedef long long LL;
bool check[MN];
LL phi[MN],prime[MN],f[MN],ans=0;
void Shaker()
{
    memset(check,0,sizeof(check));
    phi[1]=1;int tot=0;
    for(int i=2;i<MN-1;i++)
    {
        if(!check[i])
        {
            prime[tot++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<tot;j++)
        {
            if(i*prime[j]>MN-1)break;
            check[i*prime[j]]=1;
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
LL n,a[MN];
int main()
{
    Shaker();
    memset(f,0,sizeof(f));
    for(int i=1;i<MN-1;i++)
    {
        for(int k=i*2;k<MN-1;k+=i)f[k]+=(i*phi[k/i]);
    }
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        ans+=f[a[i]];
    }
    cout<<ans<<endl;
    return 0;
}
