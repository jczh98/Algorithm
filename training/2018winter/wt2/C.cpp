#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;
const int N=100005;
const int M=N*4;
int t,n,q,a[N];
int lch[M],rch[M],lazy_k[M],lazy_v[M],mul[M];
LL quickpow(LL a,LL b) {
    LL ret=1;
    for(;b;b>>=1) {
        if(b&1)ret=(ret%MOD*a%MOD)%MOD;
        a=(a%MOD*a%MOD)%MOD;
    }
    return ret;
}
void pushup(int x) {
    
}
void pushdown(int x) {
    
}
void build(int x,int l,int r) {
    lch[x]=l;rch[x]=r;
    if(l==r){seg_a[x]=a[l];seg_k[x]=1;seg_v[x]=1;return;}
    int mid=(l+r)/2;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    pushup(x);
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&q);
    }
}