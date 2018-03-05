#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int N=100005;
int n,T[N],V[N],c,sec,ans;
char rel[100],agg[100];
int lch[N*4],rch[N*4],Min[N*4],Max[N*4],sum[N];
void pushup(int x) {
    Min[x]=min(Min[x<<1],Min[x<<1|1]);
    Max[x]=max(Max[x<<1],Max[x<<1|1]);
}
void build(int x,int l,int r) {
    lch[x]=l;rch[x]=r;Min[x]=inf;Max[x]=-inf;
    if(l==r) {
        Min[x]=Max[x]=V[l]; return;
    }
    int mid=(l+r)/2;
    build(x<<1,l,mid); build(x<<1|1,mid+1,r);
    pushup(x);
}
int query_min(int x, int l, int r) {
    if(rch[x]<l||r<lch[x]) return -inf;
    if(l<=lch[x]&&rch[x]<=r) {return Min[x];}
    int mid = (lch[x]+rch[x])/2;
    if(r<=mid) return query_min(x<<1,l,r); 
    else if(l>mid) return query_min(x<<1|1,l,r);
    else return min(query_min(x<<1,l,mid),query_min(x<<1|1,mid+1,r));
}
int query_max(int x, int l, int r) {
    if(rch[x]<l||r<lch[x]) return inf;
    if(l<=lch[x]&&rch[x]<=r) {return Max[x];}
    int mid = (lch[x]+rch[x])/2;
    if(r<=mid) return query_max(x<<1,l,r); 
    else if(l>mid) return query_max(x<<1|1,l,r);
    else return max(query_max(x<<1,l,mid),query_max(x<<1|1,mid+1,r));
}
int main() {
    while(scanf("%d",&n)!=EOF) {
        sum[0]=0;
        for(int i=1;i<=n;++i) scanf("%d%d",&T[i],&V[i]), sum[i]=sum[i-1]+V[i];
        scanf("%d",&c);
        build(1,1,n);
        for(int q=1;q<=c;++q) {
            scanf("%s%s%d",rel,agg,&sec); ans=0;
            for(int i=2;i<=n;++i) {
                int pos=lower_bound(T+1,T+1+i,T[i]-sec)-T;
                if(pos==i) continue;
                if(agg[0]=='a') {
                    int sum_=sum[i-1]-sum[pos-1];
                    if(rel[0]=='l'&&V[i]*(i-pos)<sum_) ans++;
                    if(rel[0]=='g'&&V[i]*(i-pos)>sum_) ans++;
                }else if(agg[0]=='m'&&agg[1]=='i') {
                    int min_=query_min(1,pos,i-1);
                    if(rel[0]=='l'&&V[i]<min_) ans++;
                    if(rel[0]=='g'&&V[i]>min_) ans++;
                }else if(agg[0]=='m'&&agg[1]=='a') {
                    int max_=query_max(1,pos,i-1);
                    if(rel[0]=='l'&&V[i]<max_) ans++;
                    if(rel[0]=='g'&&V[i]>max_) ans++;
                }                
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}