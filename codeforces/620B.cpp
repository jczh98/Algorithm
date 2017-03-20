#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
LL ans=0;
int c[]={6,2,5,5,4,5,6,3,7,6};
int a,b;
int main()
{
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        int x=i;
        while(x)
        {
            ans+=c[x%10];
            x/=10;
        }
    }
    cout<<ans<<endl;
}
