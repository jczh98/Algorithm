#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MN 100
using namespace std;

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int n,m,k,region,cnt,flag,vis[MN][MN],ans=0;
char mat[MN][MN];

struct Node
{
    int x,y,region;

    bool operator < (const Node &rhs)const
    {
        return region<rhs.region;
    }
};

Node seq[50000];

bool Dfs(int x,int y)
{
    region++;
    vis[x][y]=1;
    if(x<=0||x>=n-1||y<=0||y>=m-1)flag=1;
    for(int i=0;i<4;i++)
    {
        int vx=x+dx[i],vy=y+dy[i];
        if(vis[vx][vy]==0&&mat[vx][vy]=='.'&&((vx>=0&&vx<n)&&(vy>=0&&vy<m)))Dfs(vx,vy);
    }
}

void Dfs2(int x,int y)
{
    mat[x][y]='*';
    for(int i=0;i<4;i++)
    {
        int vx=x+dx[i],vy=y+dy[i];
        if(mat[vx][vy]=='.'&&((vx>=0&&vx<n)&&(vy>=0&&vy<m)))Dfs2(vx,vy);
    }
    return;
}

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)scanf("%s",mat[i]);
    memset(vis,0,sizeof(vis));
    cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(vis[i][j]==0&&mat[i][j]=='.')
            {
                flag=0;region=0;
                Dfs(i,j);
                if(flag==1)continue;
                seq[cnt].x=i;seq[cnt].y=j;seq[cnt++].region=region;
            }
        }
    //for(int i=0;i<cnt;i++)printf("::%d %d %d\n",seq[i].x,seq[i].y,seq[i].region);
    sort(seq,seq+cnt);
    //for(int i=0;i<cnt;i++)printf("::%d %d %d\n",seq[i].x,seq[i].y,seq[i].region);
    for(int i=0;i<cnt-k;i++)
    {
        ans+=seq[i].region;
        Dfs2(seq[i].x,seq[i].y);
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++)printf("%s\n",mat[i]);
    return 0;
}
