#include <bits/stdc++.h>
#define MN 100010
using namespace std;
typedef long long LL;
int n,a[3*MN];
LL sum,ans=-(1e16+7),l[3*MN],r[3*MN];
priority_queue<int,vector<int>,greater<int> > pq;
priority_queue<int,vector<int>,less<int> > pq2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=3*n;i++)scanf("%d",&a[i]);
    sum=0;
    for(int i=1;i<=3*n;i++)
    {
        sum+=a[i];
        pq.push(a[i]);
        while(pq.size()>n)
        {
            sum-=pq.top();
            pq.pop();
        }
        l[i]=sum;
    }
    sum=0;
    for(int i=3*n;i>=1;i--)
    {
        sum+=a[i];
        pq2.push(a[i]);
        while(pq2.size()>n)
        {
            sum-=pq2.top();
            pq2.pop();
        }
        r[i]=sum;
    }
    for(int i=n;i<=2*n;i++)
    {
        ans=max(ans,l[i]-r[i+1]);
    }
    printf("%lld\n",ans);
    return 0;
}
