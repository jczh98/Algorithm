#include <bits/stdc++.h>
using namespace std;
int n,d1[100100],d2[100100],ans=0;
vector<int> v[100100];
void Dfs1(int x,int fa,int d)
{
    d1[x]=d;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=fa)
        {
            Dfs1(v[x][i],x,d+1);
        }
    }
}
void Dfs2(int x,int fa,int d)
{
    d2[x]=d;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]!=fa)
        {
            Dfs2(v[x][i],x,d+1);
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    Dfs1(1,0,1);
    Dfs2(n,0,1);
    for(int i=1;i<=n;i++)
    {
        if(d1[i]<=d2[i])ans++;
        else ans--;
    }
    if(ans>0)printf("Fennec\n");
    else printf("Snuke\n");
    return 0;
}
