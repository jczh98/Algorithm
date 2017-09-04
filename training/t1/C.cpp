#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
typedef long long LL;
const int M=1<<11;
int n,m;
double k;
LL cnt[M],ans=0;
int Count(int x)
{
    int sum=0;
    for(int i=0;i<10;i++)if(x&(1<<i))sum++;
    return sum;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int q,s=0,t;
        cin>>q;
        for(int j=1;j<=q;j++)cin>>t,s|=(1<<(t-1));
        cnt[s]+=1;
    }
    cin>>k;
    for(int i=0;i<1024;i++)
    {
        for(int j=i;j<1024;j++)
        {
            double up=Count(i&j),down=Count(i|j);
            if(up/down>=k)
            {
                if(i==j)ans+=cnt[i]*(cnt[i]-1)/2;
                else ans+=cnt[i]*cnt[j];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
