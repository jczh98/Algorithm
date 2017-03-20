#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int ans=1,n,s[1000000],x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<n;i++)
    {
        if((s[i]==10&&s[i+1]==1)||(s[i]==1&&s[i+1]==10))ans++;
    }
    cout<<ans<<endl;
    return 0;
}
