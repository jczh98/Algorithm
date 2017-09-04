#include <bits/stdc++.h>
#define MN 900000+10
using namespace std;
typedef long long LL;
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
int main()
{
    scanf("%s",str+1);
    string out=str+1;
    //cout<<out[0]<<endl;
    n=strlen(str+1);
    SuffixArray(256);
    //for(int i=1;i<=n;i++)cout<<"h"<<SA[i]<<" "<<height[i]<<endl;
    int q;cin>>q;
    while(q--)
    {
        LL k;cin>>k;
        LL ans=0,pos=0,len=0;
        for(int i=1;i<=n;i++)
        {
            LL cnt=n+1-SA[i]-height[i];
            //cout<<n-SA[i]<<" "<<height[i]<<endl;
            if(ans+cnt<k) ans+=cnt;
            else
            {
                pos=SA[i];len=height[i]-ans+k;
                break;
            }
        }
        cout<<out.substr(pos-1,len)<<endl;
    }
    return 0;
}
