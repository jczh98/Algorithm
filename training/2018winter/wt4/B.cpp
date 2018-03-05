#include <bits/stdc++.h>
using namespace std;
int t,n,r[1000],ans;
int main() {
    freopen("overcode.in","r",stdin);
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);ans=0;
        for(int i=1;i<=n;++i) {
            scanf("%d",&r[i]);
        }
        if(n<6) {cout<<ans<<endl;continue;}
        sort(r+1,r+1+n);
        for(int i=1;i<=n-5;) {
            if(r[i+5]-r[i]<=1000) {
                ans++;i=i+6;
            }else i++;
        }
        cout<<ans<<endl;
    }
    return 0;
}