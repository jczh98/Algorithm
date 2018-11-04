#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define SZ(x) int((x).size())
#define mp make_pair
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int,int> PII;

const LL mod=1e9+7;
const double PI=acos(-1);
const double EPS=1e-6;
const int INF=0x3f3f3f3f;
inline void read(LL& x){int f=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(f=-1,x=0):(x=c-'0');while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=f;}
inline void read(int& x){LL t;read(t);x=t;}

inline LL mulmod(LL a,LL b,LL m){
    a=a%m,b=b%m;
    return ((a*b-(LL)(((long double)a*b+0.5)/m)*m)%m+m)%m;
}
inline LL powmod(LL a,LL b,LL m){
    LL ret=1;
    for(;b;b>>=1){
        if(b&1) ret=mulmod(ret,a,m);
        a=mulmod(a,a,m);
    }
    return ret;
}
inline bool Miller_Rabin(LL n){
    if(n==2) return true;
    if(n<2||!(n&1)) return false;
    LL m,x,y;
    int k=0;
    for(k,m=n-1;!(m&1);m>>=1,k++);
    for(register int i=0;i<5;i++){//测试次数，一般5次足够了
        x=rand()%(n-2)+2;
        if(!(x%n)) continue;
        x=powmod(x,m,n);
        LL y=x;
        for(register int j=0;j<k;j++){
            x=mulmod(x,x,n);
            if(x==1&&y!=1&&y!=n-1) return false;
            y=x;
        }
        if(x!=1) return false;
    }
    return true;
}
inline LL Pollard_Rho(LL n,LL c){
    LL x=rand();
    LL y=x;
    for(register LL i=1,k=2;;i++){
        x=(mulmod(x,x,n)+c)%n;
        LL d=__gcd(y>x?y-x:x-y,n);
        if(1<d&&d<n) return d;
        if(y==x) return n;
        if(i==k){
            y=x;k<<=1;
        }
    }
}
int cnt;
LL fac[1000]; //存储质因数及其次数
inline void factor(LL n, int c){//测试次数，大概100次就足够了
    if(n==1) return;
    if(Miller_Rabin(n)){
        fac[cnt++]=n;return;
    }
    LL p=n,k=c;
    while(p==n) p=Pollard_Rho(n,c--);
    factor(p,c);
    factor(n/p,c);
}
LL ans;
inline void Solve(LL n) {
    cnt = 0;
    factor(n, 3000);
    for(register int i = 0; i < cnt; ++i) {
        ans += fac[i] - 1;
    }
}
LL t, nn;
int main() {
    //freopen("out2.txt", "w", stdout);
    scanf("%lld", &t);
    //for(register LL nn = 1; nn <= 100000; ++nn) {
    while(t--) {
        scanf("%lld", &nn);
        if(nn == 1) {
            printf("0\n"); continue;
        }
        ans = 0;
        Solve(nn);
        printf("%lld\n", ans);
    }
}