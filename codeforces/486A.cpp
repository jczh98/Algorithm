#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
LL n,ans;
int main()
{
    cin>>n;
    if(n%2==0)ans=n/2;else ans=(-1)*(n+1)/2;
    cout<<ans<<endl;
    return 0;
}
