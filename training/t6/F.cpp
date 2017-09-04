#include <bits/stdc++.h>
#define MN 300000
using namespace std;
int n,m;
struct Node
{
    int x,lane;
    bool operator < (const Node& rhs) const
    {
        return x<rhs.x;
    }
}node[MN];
int st[MN],ed[MN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&node[i].x,&node[i].lane);
    }
    sort(node+1,node+1+m);
    for(int i=1;i<=n;i++)st[i]=ed[i]=i;
    for(int i=1;i<=m;i++)
    {
        st[node[i].lane]=st[node[i].lane+1]=min(st[node[i].lane],st[node[i].lane+1]);
        ed[node[i].lane]=ed[node[i].lane+1]=max(ed[node[i].lane],ed[node[i].lane+1]);
    }
    /*for(int i=1;i<=n;i++)
    {
        cout<<st[i]<<" "<<ed[i]<<endl;
    }*/
    for(int i=1;i<n;i++)printf("%d ",ed[i]-st[i]+1);
    printf("%d\n",ed[n]-st[n]+1);
    return 0;
}
