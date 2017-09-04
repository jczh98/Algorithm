#include <bits/stdc++.h>
using namespace std;
int n,w,h,I,x,y,cntt=0;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0},vis[500][500];
char mp[300][300];
void Bfs(int x,int y)
{
    memset(vis,0,sizeof(vis));
    queue<pair<int,int>> que;
    que.push(make_pair(x,y));
    vis[x][y]=1;
    while(!que.empty())
    {
        int nowx=que.front().first,nowy=que.front().second;que.pop();
        //if(vis[nowx][nowy]>=2)continue;
        for(int i=0;i<=3;i++)
        {
            int vx=nowx+dx[i],vy=nowy+dy[i];
            //if(cntt==5)cout<<nowx<<" "<<nowy<<" "<<vx<<" "<<vy<<endl;
            if(vx>=0&&vx<w&&vy<h&&vy>=0)
            {
                //if(cntt==5&&nowx==6&&nowy==4)cout<<"hh"<<vx<<" "<<vy<<endl;
                //cout<<mp[vy][vx]<<endl;
                if(mp[vy][vx]=='X')continue;
                else if(mp[vy][vx]=='D')
                {
                    if(vis[vx][vy])continue;
                    vis[vx][vy]=1;
                    que.push(make_pair(vx,vy));
                }else mp[vy][vx]++;
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    while(n--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&w,&h);
        for(int i=0;i<h;i++)
        {
            scanf("%s",mp[i]);
        }
        scanf("%d",&I);
        while(I--)
        {
            scanf("%d%d",&x,&y);
            //if(x==6&&y==4)cntt++;
            if(mp[y][x]=='X') continue;
            else if(mp[y][x]=='D')
            {
                Bfs(x,y);
            }else mp[y][x]++;
            //for(int i=0;i<h;i++)printf("%s\n",mp[i]);
        }
        for(int i=0;i<h;i++)printf("%s\n",mp[i]);
    }
    return 0;
}
