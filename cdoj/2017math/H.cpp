#include <bits/stdc++.h>
#define MN 300300
using namespace std;
int n,stone[MN],fa[MN],sum;
vector<int> v[MN],vv[MN];
void Dfs(int u,int &xor0,int &xor1)
{
    xor0=stone[u];xor1=0;int t1=0,t0=0;
    for(int i=0;i<v[u].size();i++)
    {
        t1=t0=0;
        Dfs(v[u][i],t1,t0);
        xor1^=t1,xor0^=t0;
    }
    if(xor0)sum++;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(int i=0;i<n;i++)v[i].clear();
        for(int i=1;i<n;i++)scanf("%d",&fa[i]),v[fa[i]].push_back(i);
        for(int i=0;i<n;i++)scanf("%d",&stone[i]);
        int x1=0,x0=0;
        Dfs(0,x0,x1);
        printf("%d\n",sum);
    }
    return 0;
}
