#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int t,n,v,a[100005],ans;
int lch[4*N],rch[4*N];
LL seg_or[4*N];
void pushup(int x) {seg_or[x]=seg_or[x<<1]|seg_or[x<<1|1];}
void build(int x,int l,int r) {
    lch[x]=l;rch[x]=r;seg_or[x]=0;
    if(l==r) {
        seg_or[x]=a[l];return;
    }
    int mid=(l+r)/2;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
int query(int x, int l, int r) {
    if(l<=lch[x]&&r>=rch[x]) {return seg_or[x];}
    int mid = (lch[x]+rch[x])/2;
    if(r<=mid) return query(x<<1,l,r); 
    else if(l>mid) return query(x<<1|1,l,r);
    else return query(x<<1,l,mid)|query(x<<1|1,mid+1,r);
}
bool check(int x) {
    for(int i=1;i<=n;++i) {
        if(i+x-1<=n&&query(1,i,i+x-1)<=v) { return true; }
    }
    return false;
}
int main() {
    freopen("wifi.in","r",stdin);
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&v);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        build(1,1,n);
        int L=1,R=n;ans=0;
        while(L<=R) {
            int mid=(L+R)/2;
            if(check(mid)) {
                ans=mid;L=mid+1;
            }else {
                R=mid-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}