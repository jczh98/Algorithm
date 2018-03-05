#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,readin;
pii f[100005];
pii query(int x) {
    pii ret=make_pair(0,1);
    while(x) {
        if(f[x].first>ret.first)ret=f[x];
        else if(f[x].first==ret.first)ret.second=(ret.second+f[x].second)%m;
        x-=x&(-x);
    }
    return ret;
}
void add(int x,pii v) {
    while(x<=n) {
        if(f[x].first<v.first)f[x]=v;
        else if(f[x].first==v.first)f[x].second=(f[x].second+v.second)%m;
        x+=x&(-x);
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) {
        scanf("%d",&readin);
        pii t=query(readin);
        t.first++;
        add(readin,t);
    }
    printf("%d\n",query(n).second);
    return 0;
}