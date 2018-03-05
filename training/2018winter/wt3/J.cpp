#include <bits/stdc++.h>
using namespace std;
int n,m,q,a[30000005],c,cnt[30000005],ans[30000005],counter=0;
int main() {
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;++i) {
        scanf("%d",&a[i]);cnt[a[i]]++;
    }
    for(int i=m+1;i<=n;++i) {
        a[i]=(a[i-m]+a[i-m+1])%30000000;
        cnt[a[i]]++;
    }
    for(int i=0;i<30000000;++i) {
        for(int j=0;j<cnt[i];++j) {
            ans[++counter]=i;
        }
    }
    for(int i=1;i<=q;++i) {
        scanf("%d",&c);
        printf("%d\n",ans[c]);
    }
    return 0;
}