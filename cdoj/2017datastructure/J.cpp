#include <bits/stdc++.h>
#define MN 20100
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
int n,sb[MN],wtmsb,ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&wtmsb);
        pq.push(wtmsb);
    }
    while(pq.size()>=2)
    {
        int p1=pq.top();pq.pop();
        int p2=pq.top();pq.pop();
        ans+=p1+p2;
        pq.push(p1+p2);
    }
    printf("%d\n",ans);
    return 0;
}
