#include <bits/stdc++.h>
using namespace std;
int t,n,a[5005],b[5005],ans,cnt[5005],odd,code[5005],vis[1000005],counter;
int main() {
    freopen("cases.in","r",stdin);
    scanf("%d",&t);
    while(t--) {
        memset(vis,0,sizeof(vis));counter=1;
        scanf("%d",&n);ans=0;
        for(int i=1;i<=n;++i) {
            scanf("%d",&a[i]);b[i]=a[i];
        }
        sort(b+1,b+1+n);
        for(int i=1;i<=n;++i) {
            if(!vis[b[i]])vis[b[i]]=counter++;
        }
        for(int i=1;i<=n;++i) {
            a[i]=vis[a[i]];
        }
        for(int i=1;i<=n;++i) {
            odd=0;
            for(int i=1;i<=n;++i)cnt[i]=0;
            for(int j=i;j<=n;++j) {
                cnt[a[j]]++;
                if(cnt[a[j]]&1) {
                    odd++;
                }else {
                    odd--;
                }
                if(odd==1) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}