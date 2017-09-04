#include <bits/stdc++.h>
#define MN 100010
using namespace std;
char str[MN];
int SA[MN],a[MN],rk[MN],height[MN],helper[MN],rk_helper[MN],n,m,k,mx=0,ans;
void RadixSort()
{
    for(int i=0;i<=m;i++)helper[i]=0;
    for(int i=1;i<=n;i++)helper[rk[rk_helper[i]]]++;
    for(int i=1;i<=m;i++)helper[i]+=helper[i-1];
    for(int i=n;i>=1;i--)SA[helper[rk[rk_helper[i]]]--]=rk_helper[i];
}
int cmp(int *f,int x,int y,int w){return f[x]==f[y]&&f[x+w]==f[y+w]; }
void SuffixArray(int x)
{
    for(int i=1;i<=n;i++)rk[i]=a[i],rk_helper[i]=i;
    m=x;RadixSort();
    for(int w=1,p=1,i;p<n;w<<=1,m=p)
    {
        for(p=0,i=n-w+1;i<=n;i++)rk_helper[++p]=i;
        for(i=1;i<=n;i++)if(SA[i]>w)rk_helper[++p]=SA[i]-w;
        RadixSort();swap(rk,rk_helper);rk[SA[1]]=p=1;
        for(int i=2;i<=n;i++)rk[SA[i]]=cmp(rk_helper,SA[i],SA[i-1],w)?p:++p;
    }
    int j,k=0;
    for(int i=1;i<=n;height[rk[i++]]=k)
    {
        for(k=k?k-1:k,j=SA[rk[i]-1];a[i+k]==a[j+k];k++);
    }
}
bool Judge(int x)
{
    int t=0;
    for(int i=1;i<=n;i++)
    {
        if(height[i]<x)continue;
        int cnt=2,j;
        for(j=i+1;j<=n;j++)
        {
            if(height[j]<x)break;
            cnt++;
        }
        t=max(t,cnt);
        j=i;
    }
    return t>=k;
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx=max(mx,a[i]);
    SuffixArray(mx);
    //for(int i=1;i<=n;i++)cout<<height[i]<<endl;
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(Judge(mid))
        {
            ans=mid;l=mid+1;
        }else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
