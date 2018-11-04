#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=3e5+10;
char s[N];int cur=1,cnt=1,n,last,ch[M][26],fa[M],dis[M],sz[M];long long ans=0;
void build(int c,int id){
    last=cur;cur=++cnt;
    int p=last;dis[cur]=id;
    for(;p && !ch[p][c];p=fa[p])ch[p][c]=cur;
    if(!p)fa[cur]=1;
    else{
        int q=ch[p][c];
        if(dis[q]==dis[p]+1)fa[cur]=q;
        else{
            int nt=++cnt;dis[nt]=dis[p]+1;
            memcpy(ch[nt],ch[q],sizeof(ch[q]));
            fa[nt]=fa[q];fa[q]=fa[cur]=nt;
            for(;ch[p][c]==q;p=fa[p])ch[p][c]=nt;
        }
    }
    sz[cur]=1;
}
int c[N],sa[M];
int a, b;
void flower(){
    memset(c,0,sizeof(c));
    memset(sa,0,sizeof(sa));
    for(int i=1;i<=cnt;i++)c[dis[i]]++;
    for(int i=1;i<=n;i++)c[i]+=c[i-1];
    for(int i=cnt;i>=1;i--)sa[c[dis[i]]--]=i;
    for(int i=cnt;i;i--){
        int p=sa[i];
        if(sz[p]>=a&&sz[p]<=b){
            ans+=dis[p]-dis[fa[p]];
        }
        sz[fa[p]]+=sz[p];
    }
}
void work(){
    while(scanf("%s%d%d",s+1, &a, &b) != EOF) {
        memset(ch, 0, sizeof(ch));
        memset(dis, 0, sizeof(dis));
        memset(sz, 0, sizeof(sz));
        memset(fa, 0, sizeof(fa));
        cur = cnt = 1;
        ans = 0;
        n=strlen(s+1);
        for(int i=1;i<=n;i++)build(s[i]-'A',i);
        flower();
        printf("%lld\n",ans);        
    }

}
int main()
{
    work();
    return 0;
}