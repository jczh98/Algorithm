#include <bits/stdc++.h>
using namespace std;
int t,n,m,x,s[40],ans,cnt;
void cut(int a,int b) {
    if(a<b) swap(a,b);
    if(a<=0||b<=0) return;
    if(cnt>n)return;
    int v;
    for(int k=31;k>=0;--k) {
        v=(1<<k);
        if(v<=b&&s[k]>0) {
            s[k]--;cnt++;
            cut(a-v,b);cut(v,b-v);
            return;
        }
    }
}
int main() {
    scanf("%d",&t);
    while(t--) {
        memset(s,0,sizeof(s));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i) scanf("%d",&x),s[x]++;
        cnt=1;ans=0;
        while(cnt<=n) {
            cut(m,m);ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}