#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;
typedef long long LL;

int n,kase=1;
LL mmax,sum,a[25];

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n&&n)
    {
        mmax=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            sum=1;
            for(int j=i;j<=n;j++)
            {
                sum*=a[j];
                if(mmax<sum)mmax=sum;
            }
        }
        cout<<"Case #"<<kase++<<": The maximum product is "<<mmax<<".\n\n";
    }
    return 0;
}
