#include <bits/stdc++.h>
#define MN 10000+10
using namespace std;
char str[MN];
int SA[MN],rk[MN],height[MN],hp[MN],rhp[MN],n,m;
void RadixSort()
{
    for(int i=0;i<=m;i++)hp[i]=0;
    for(int i=1;i<=n;i++)hp[rk[rhp[i]]]++;
    for(int i=1;i<=m;i++)hp[i]+=hp[i-1];
    for(int i=n;i>=1;i--)SA[hp[rk[rhp[i]]]--]=rhp[i];
}
int cmp(int *f,int x,int y,int w){return f[x]==f[y]&&f[x+w]==f[y+w]; }
void SuffixArray(int x)
{
    for(int i=1;i<=n;i++)rk[i]=str[i],rhp[i]=i;
    m=x;RadixSort();
    for(int w=1,p=0,i;p<n;w+=w,m=p)
    {
        for(p=0,i=n-w+1;i<=n;i++)rhp[++p]=i;
        for(i=1;i<=n;i++)if(SA[i]>w)rhp[++p]=SA[i]-w;
        RadixSort();swap(rk,rhp);rk[SA[1]]=p=1;
        for(int i=2;i<=n;i++)rk[SA[i]]=cmp(rhp,SA[i],SA[i-1],w)?p:++p;
    }
    int j,k=0;
    for(int i=1;i<=n;height[rk[i++]]=k)
    {
        for(k=k?k-1:k,j=SA[rk[i]-1];str[i+k]==str[j+k];k++);
    }
}
int Log[MN];
int best[30][MN];

void setLog()
{
    Log[0] = -1;
    for(int i=1; i<MN; i++)
    {
        Log[i]=(i&(i-1))?Log[i-1]:Log[i-1] + 1 ;
    }
}
void RMQ(int n)  //初始化RMQ
{
    for(int i = 1; i <= n ; i ++) best[0][i] = height[i];
    for(int i = 1; i <= Log[n] ; i ++)
    {
        int limit = n - (1<<i) + 1;
        for(int j = 1; j <= limit ; j ++)
        {
            best[i][j] = min(best[i-1][j] , best[i-1][j+(1<<i>>1)]);
        }
    }
}
int LCP(int a,int b)  //询问a,b后缀的最长公共前缀
{
    a ++;
    int t = Log[b - a + 1];
    return min(best[t][a] , best[t][b - (1<<t) + 1]);
}
int Solve(int l, int r)
{
    int ans = (r-l+1)*(r-l+2)/2;
    int last = -1;
    int cnt = r-l+1;
    for(int i = 1; i<=n; i++)
    {
        if(!cnt) break;
        if(SA[i] < l || SA[i] > r) continue;
        cnt--;
        if(last == -1)
        {
            last = i;
            continue;
        }
        int a = last;
        int b = i;
        if(a>b) swap(a,b);
        int lcp = LCP(a,b);
        int la = r-SA[last]+1;//区间内该串的尾部
        int lb = r-SA[i]+1;
        if(la>=lb && lcp>=lb);//la包含lb了，那么就用la继续往后比较，借此保持字典序，来模拟得到该区间的所有height
        else last = i;
        ans-=min(lcp,min(la,lb));
    }
    return ans;
}
int q, w, id;
int main() {
    scanf("%s", str + 1);
    n = strlen(str + 1);
    SuffixArray(256);
    RMQ(n);
    scanf("%d%d", &q, &w);
    for(int i = 1; i <= q; i++) {
        scanf("%d", &id);
        printf("%d\n", Solve(id, id + w - 1));
    }
    return 0;
}
