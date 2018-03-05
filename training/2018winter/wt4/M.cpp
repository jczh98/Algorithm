#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
LL n,k;
int main() {
    freopen("chess.in","r",stdin);
    scanf("%d",&t);
    while(t--) {
        cin>>n>>k;
        LL a=n/(k+1),b=n%(k+1);
        LL ans=n*n-a*a*(k+1-b)-(a+1)*(a+1)*b;
        cout<<ans<<endl;
    }
    return 0;
}