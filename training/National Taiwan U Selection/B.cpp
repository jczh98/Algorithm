#include <bits/stdc++.h>
#define pa pair<int,int>
#define inf 0x3f3f3f3f
#define mp make_pair
using namespace std;

const int maxn=100000+5,mod=1e9+7;

int n,tot,anscnt,a[maxn],s[maxn],t[maxn],fac[maxn];
long long sum;

struct Trie{
    int cnt,nxt[2];
}tr[maxn*30];

inline int read(void){
    char ch=getchar();int x=0;
    while(!(ch>='0'&&ch<='9')) ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x;
}

inline void init(void){
    for(int i=0;i<=tot;i++)
        tr[i].nxt[0]=tr[i].nxt[1]=tr[i].cnt=0;
    tot=0;
}

inline void insert(int x){
    int p=0;
    for(int i=30,y;i>=0;i--){
        y=(x>>i)&1;
        if(!tr[p].nxt[y])
            tr[p].nxt[y]=++tot;
        p=tr[p].nxt[y];
    }
    tr[p].cnt++;
}

inline pa find(int x){
    int p=0,ans=0;
    for(int i=30,y;i>=0;i--){
        y=(x>>i)&1;
        if(tr[p].nxt[y]) p=tr[p].nxt[y],ans|=y<<i;
        else p=tr[p].nxt[y^1],ans|=(y^1)<<i;
    }
    return mp(ans^x,tr[p].cnt);
}

inline int power(int x,int y){
    int res=1;
    while(y){
        if(y&1) res=1LL*res*x%mod;
        x=1LL*x*x%mod,y>>=1;
    }
    return res;
}

inline void solve(int l,int r,int dep){
    if(l>=r) return;
    if(dep<0){
        if(r-l+1>=2)
            anscnt=1LL*anscnt*power(r-l+1,r-l-1)%mod;
        return;
    }
    int cnt1=0,cnt2=0;
    for(int i=l;i<=r;i++)
        if((a[i]>>dep)&1) s[cnt1++]=a[i];
        else t[cnt2++]=a[i];
    for(int i=0;i<cnt1;i++) a[l+i]=s[i];
    for(int i=0;i<cnt2;i++) a[l+cnt1+i]=t[i];
    init();pa tmp;int ans=inf,cnt=0;
    for(int i=0;i<cnt2;i++) insert(t[i]);
    for(int i=0;i<cnt1;i++){
        tmp=find(s[i]);
        if(tmp.first<ans)
            ans=tmp.first,cnt=tmp.second;
        else if(tmp.first==ans)
            cnt+=tmp.second;
    }
    if(sum!=inf&&cnt) sum+=ans,anscnt=1LL*cnt*anscnt%mod;
    solve(l,l+cnt1-1,dep-1);solve(l+cnt1,r,dep-1);
}

int main(void){
    n=read(),anscnt=1;fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=1LL*fac[i-1]*i%mod;
    for(int i=1;i<=n;i++) a[i]=read();
    solve(1,n,30);
    printf("%lld\n",sum);
    return 0;
}