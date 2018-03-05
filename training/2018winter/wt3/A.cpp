#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline void read(LL &v) {
    v=0;char c=0;int p=1;
    while(c<'0'||c>'9'){if(c=='-')p=-1;c=getchar();}
    while(c>='0'&&c<='9'){v=(v<<3)+(v<<1)+c-'0';c=getchar();}
    v*=p;
}
const int L=19;
const int N=1000100;
LL a[1000050],digit[N][50];
int ch[N*20][10],val[N*20];
int n,sz=1;
inline void insert(LL x) {
    int u=0;
    for(int i=L;i>=1;--i) {
        int v=digit[x][i];
        if(!ch[u][v]) {
            memset(ch[sz],0,sizeof(ch[sz]));
            val[sz]=0; ch[u][v]=sz++;
        }
        u=ch[u][v]; val[u]++;
    }
}
inline void del(LL x) {
    int u=0;
    for(int i=L;i>=1;--i) {
        int v=digit[x][i]; u=ch[u][v]; val[u]--;
    }
}
inline LL query_min(LL x) {
    LL ret=0; int u=0;
    for(int i=L;i>=1;--i) {
        int Min=10,pos,v=digit[x][i];
        for(int j=0;j<=9;++j) {
            if(val[ch[u][j]]) {
                if((j+v)%10<Min) { Min=(j+v)%10; pos=j; }
            }
        }
        u=ch[u][pos]; ret=ret*10+Min;
    }
    return ret;
}
inline LL query_max(LL x) {
    LL ret=0;int u=0;
    for(int i=L;i>=1;--i) {
        int Max=-1,pos,v=digit[x][i];
        for(int j=0;j<=9;++j) {
            if(val[ch[u][j]]) {
                if((j+v)%10>Max) { Max=(j+v)%10;pos=j; }
            }
        }
        u=ch[u][pos]; ret=ret*10+Max;
    }
    return ret;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        read(a[i]);
        int k=1,c=a[i];
        while(c) { digit[i][k++]=c%10;c/=10; }
        insert(i);
    }
    LL Max=-1,Min=1e18+5;
    for(int i=1;i<=n;++i) {
        del(i);
        Max=max(Max,query_max(i));
        Min=min(Min,query_min(i));
        insert(i);
    }
    cout<<Min<<" "<<Max<<endl;
    return 0;
}