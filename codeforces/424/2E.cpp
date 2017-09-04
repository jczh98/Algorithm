#include <bits/stdc++.h>
#define MN 110000
using namespace std;
typedef long long LL;
int C[MN],n,a[MN];
LL ans=0;
vector<int> pos[MN];
int Lowbit(int x)
{
    return x&(-x);
}
void Add(int x,int num)
{
    while(x<=n)
    {
        C[x]+=num;
        x+=Lowbit(x);
    }
}
int Sum(int x)
{
    int sum=0;
    while(x)
    {
        sum+=C[x];
        x-=Lowbit(x);
    }
    return sum;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]].push_back(i);
    sort(a+1,a+1+n);
    int now=0;
    for(int i=1;i<=n;)
    {
        int p=lower_bound(pos[a[i]].begin(),pos[a[i]].end(),now)-pos[a[i]].begin();
        if(p==0)
        {
            int t=pos[a[i]][pos[a[i]].size()-1];
            ans+=t-Sum(t)-(now-Sum(now));
            now=t;
        }else
        {
            int t=pos[a[i]][p-1];
            ans+=n-Sum(n)-(now-Sum(now))+(t-Sum(t));
            now=t;
        }
        for(int j=0;j<pos[a[i]].size();j++)Add(pos[a[i]][j],1);
        i+=pos[a[i]].size();
    }
    cout<<ans<<endl;
    return 0;
}
