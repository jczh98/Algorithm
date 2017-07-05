#include <bits/stdc++.h>
#define N 10000
using namespace std;
typedef pair<int,int> pii;
int n,k[2],sk[N][2],f[N][2],deg[N][2];
void Bfs(int x,int y)
{
    queue<pii> que;
    que.push(make_pair(x,y));
    while(!que.empty())
    {
        pii now=que.front();que.pop();
        int last=now.second^1;
        for(int i=1;i<=k[last];i++)
        {
            int v=(now.first-sk[i][last]+n)%n;
            if(f[v][last])continue;
            else if(f[now.first][now.second]==1)
            {
                deg[v][last]--;
                if(!deg[v][last])f[v][last]=2,que.push(make_pair(v,last));
            }else
            {
                f[v][last]=1;que.push(make_pair(v,last));
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    scanf("%d",&k[0]);for(int i=1;i<=k[0];i++)scanf("%d",&sk[i][0]);
    scanf("%d",&k[1]);for(int i=1;i<=k[1];i++)scanf("%d",&sk[i][1]);
    f[0][0]=f[0][1]=2;
    for(int i=1;i<=n;i++)
    {
        deg[i][0]=k[0];deg[i][1]=k[1];
    }
    Bfs(0,0);
    Bfs(0,1);
    for(int j=0;j<=1;j++)
    {
        for(int i=1;i<n;i++)
        {
            if(!f[i][j])printf("Loop ");
            else if(f[i][j]==1)printf("Win ");
            else printf("Lose ");
        }
        printf("\n");
    }
    return 0;
}
