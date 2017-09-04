#include <bits/stdc++.h>
#define MN 10000
using namespace std;
int n,a[MN],deg[MN]={0};
vector<int> nodes[MN];
void AddEdge(int u,int v)
{
    nodes[u].push_back(v);
    nodes[v].push_back(u);
}
int main()
{
    //freopen("in.txt","r",stdin);
    n=1;
    while(scanf("%d",&a[n])!=EOF)
    {
        deg[a[n]]++;
        n++;
    }
    int mx=a[n-1];
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=mx;j++)
        {
            if(deg[j]==0)
            {
                AddEdge(a[i],j);
                deg[a[i]]--;deg[j]--;
                break;
            }
        }
    }
    for(int i=1;i<=mx;i++)
    {
        sort(nodes[i].begin(),nodes[i].end());
    }
    for(int i=1;i<=mx;i++)
    {
        printf("%d: ",i);
        for(int j=0;j<nodes[i].size()-1;j++)
        {
            printf("%d ",nodes[i][j]);
        }
        printf("%d\n",nodes[i][nodes[i].size()-1]);
    }
    return 0;
}
