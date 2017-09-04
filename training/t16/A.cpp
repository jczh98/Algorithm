#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t,n,a,ans;
LL Sg(LL x){if(x&1)return Sg(x/2);else return x/2;}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            ans^=Sg(a);
        }
        if(ans) cout<<"YES"<<endl;else cout<<"NO"<<endl;
    }
    return 0;
}
