#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
LL ans,n,k,w;
int main()
{
    cin>>k>>n>>w;
    ans=w*(1+w)*k/2-n;
    if(ans<0)ans=0;
    cout<<ans<<endl;
}
