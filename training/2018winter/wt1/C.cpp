#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pii;
int t,n,dp[300];
pii wc[300];
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=1;i<=n;++i) {
            scanf("%lf%lf",&wc[i].first,&wc[i].second);
        }
        for(int i=1;i<=n;++i){
            dp[i]=1;
            for(int j=1;j<i;++j){
                if(wc[i].second<wc[j].second&&wc[i].first>wc[j].first&&dp[j]+1>dp[i]) dp[i]=dp[j]+1;
            }
        }
        int Max=0;
        for(int i=1;i<=n;++i)Max=max(Max,dp[i]);
        printf("%d\n",Max);
    }
}