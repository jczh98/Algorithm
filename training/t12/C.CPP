#include <bits/stdc++.h>
#define SPACE 0
using namespace std;
typedef pair<int,int> pii;
int n,m;
char mp[100][100],color[5]={'B','G','R','W','Y'},vis_color[1000],cnt_color[10];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool FindFigure()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(mp[i+dx[k]][j+dy[k]]==mp[i][j])
                {
                    return true;
                }
            }
        }
    }
    return false;
}
bool JudgeFigure(char ma)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(mp[i+dx[k]][j+dy[k]]==mp[i][j])
                {
                    if(mp[i][j]!=color[ma])
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
bool JudgeFigureMain(char ma)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<4;k++)
            {
                if(mp[i+dx[k]][j+dy[k]]==mp[i][j])
                {
                    if(mp[i][j]==color[ma])
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int Bfs(int x,int y,char c)
{
    int cnt=0;
    queue<pii > que;
    que.push(make_pair(x,y));
    while(!que.empty())
    {
        pii now=que.front();que.pop();
        for(int i=0;i<4;i++)
        {
            int nx=now.first+dx[i],ny=now.second+dy[i];
            if(mp[nx][ny]==c)
            {
                cnt++;
                que.push(make_pair(nx,ny));
            }
        }
    }
    return cnt;
}
void Remove(int ma)
{
    int max_cnt=0,t,max_c;
    pii max_pos;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            t=Bfs(i,j,mp[i][j]);
            if(max_cnt<t&&mp[i][j]!=ma)
            {
                max_cnt=t;max_c=mp[i][j];
                max_pos.first=i;max_pos.second=j;
            }
        }
    }
    queue<pii > que;
    que.push(max_pos)
    {
        pii now=que.front();que.pop();
        for(int i=0;i<4;i++)
        {
            int nx=now.x+dx[i],ny=now.y+dy[i];
            if(mp[nx][ny]==max_c)
            {
                mp[nx][ny]=SPACE;
                que.push(make_pair(nx,ny));
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            if(mp[i][j]!=SPACE)
            {
                int k=i;
                while(k>=1&&mp[k-1][j]==SPACE)
                {
                    swap(mp[k][j],mp[i-1][j]);
                    k--;
                }
            }
        }
    }
    for(int j=0;j<m;j++)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(mp[i][j]==SPACE)
            {
                cnt++;
            }
        }
        if(cnt==n)
        {

        }
    }
}
int main()
{
    memset(vis_color,0,sizeof(vis_color));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",mp[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            vis_color[mp[i][j]]=1;
        }
    }
    for(int main_color=0;main_color<5;main_color++)
    {
        if(vis_color[color[main_color]])
        {
            while(FindFigure())
            {
                while(JudgeFigure(main_color))
                {
                    Remove(main_color);
                }
                if(JudgeFigureMain(main_color))
                {

                }
            }
        }
    }
    return 0;
}
