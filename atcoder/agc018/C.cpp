#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;
int x,y,z,A[100100],B[100100],C[100100],tot,vis[100100];
LL sum=0;
priority_queue<pii > pq1,pq2,pq3;
int main()
{
    scanf("%d%d%d",&x,&y,&z);
    tot=x+y+z;
    for(int i=1;i<=tot;i++)
    {
        scanf("%d%d%d",&A[i],&B[i],&C[i]);
        sum+=A[i];
    }
    for(int i=1;i<=tot;i++)
    {
        pq1.push(make_pair(B[i]-A[i],i));
    }
    for(int i=1;i<=y;i++)
    {
        pii now=pq1.top();pq1.pop();
        vis[now.second]=1;
        sum+=now.first;
    }
    while(!pq1.empty())pq1.pop();
    for(int i=1;i<=tot;i++)
    {
        if(!vis[i])
        {
            pq2.push(make_pair(C[i]-A[i],i));
            pq3.push(make_pair(B[i]-A[i],i));
        }else
        {
            pq1.push(make_pair(C[i]-B[i],i));
        }
    }
    for(int i=1;i<=z;i++)
    {
        while(vis[pq2.top().second])pq2.pop();
        while(vis[pq3.top().second])pq3.pop();
        pii now1=pq1.top(),now2=pq2.top(),now3=pq3.top();
        if(now2.first>=now1.first+now3.first)
        {
            vis[now2.second]=1;
            sum+=now2.first;
            pq2.pop();
        }else
        {
            vis[now1.second]=vis[now3.second]=1;
            sum+=now1.first+now3.first;
            pq1.pop();
            pq1.push(make_pair(C[now3.second]-B[now3.second],now3.second));
            pq3.pop();
        }
    }
    printf("%lld\n",sum);
    return 0;
}
