#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL x,ans=0;
int main()
{
    cin>>x;
    while(x)
    {
        if(x&1)
        {
            ans++;
        }
        x>>=1;
    }
    cout<<ans<<endl;
    return 0;
}
