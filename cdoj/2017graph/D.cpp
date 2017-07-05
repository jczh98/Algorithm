#include <bits/stdc++.h>
#define MN 1010
using namespace std;
char str[MN][MN];
int n,indeg[100],ans[100],cnt=1;
vector<int> mp[200];
int Topo()
{
    priority_queue<int,vector<int>,greater<int> > Q;
    for(int i=1;i<=26;i++)
    {
        if(!indeg[i])Q.push(i);
    }
    while(!Q.empty())
    {
        int u=Q.top();Q.pop();ans[cnt++]=u;
        for(int i=0;i<mp[u].size();i++)
        {
            int v=mp[u][i];
            indeg[v]--;if(!indeg[v])Q.push(v);
        }
    }
    for(int i=1;i<=26;i++)if(indeg[i])return false;
    return true;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%s",str[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int len1=strlen(str[i]),len2=strlen(str[j]);
            for(int k=0;k<len1;k++)
            {
                if(k>len2-1)
                {
                    printf("-1\n");return 0;
                }else if(str[i][k]!=str[j][k])
                {
                    int u=str[i][k]-'a'+1,v=str[j][k]-'a'+1;
                    mp[u].push_back(v);
                    indeg[v]++;
                    break;
                }
            }
        }
    }
    if(!Topo())
    {
        printf("-1\n");
    }else
    {
        for(int i=1;i<=26;i++)
        {
            printf("%c",ans[i]+'a'-1);
        }
        printf("\n");
    }
    return 0;
}
