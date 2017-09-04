#include <bits/stdc++.h>
#define inf 0x7f7f7f7f
using namespace std;
int n,m,vis[10000],s[10000],dep[10000],son[10000];
vector<int> v[2000];
void Bfs(){
    queue <int> que;que.push(1);dep[1]=1;vis[1]=0;
    while(!que.empty()){
        int now=que.front();que.pop();
        for(int i=0;i<v[now].size();i++){
            int to=v[now][i];
            if(dep[to]>dep[now]){
                son[now]++;
                vis[to]=vis[now]^1;
                if(dep[to]==inf)que.push(to);
                dep[to]=dep[now]+1;
            }
        }
    }
}
int Dfs(int x){
    if(!son[x]) return vis[x];
    int t=0;
    for(int i=0;i<v[x].size();i++)
    {
        int to=v[x][i];
        if(dep[to]>dep[x])
        {
            t+=Dfs(to);
        }
    }
    if(!vis[x])return t>0;
    else return t==son[x];
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d",&n,&m);
    memset(vis,0,sizeof(vis));
    memset(dep,127,sizeof(dep));
    memset(son,0,sizeof(son));
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    Bfs();
    //for(int i=1;i<=n;i++)cout<<son[i]<<" "<<dep[i]<<endl;
    if(!Dfs(1))printf("Nikolay\n");
    else printf("Vladimir\n");
    return 0;
}
