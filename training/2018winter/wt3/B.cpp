#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,a[100];
LL ans=1,tmp=1;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;++i) {
        tmp*=1LL*a[i];ans+=tmp;
    }
    cout<<ans<<endl;
}