#include <bits/stdc++.h>
//
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#define ff(i,x,y) for(int i=x;i<y+1;i++)
#define fs(i,x,y) for(int i=x;i>y-1;i--)
using namespace std;
typedef long long ll;
int n,m;
char s[110][110];
bool vis[110][110][1100];
struct node
{
    int st,posx,posy,ti;
    node(int a=0,int b=0, int c=0,int d=0)
    {
        posx=a;
        posy=b;
        st=c;
        ti=d;
    }
};
queue<node>p;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
inline bool check(int x,int y)
{
    if(x>n||x<1||y>m||y<1)
        return false;
    return true;
}
void work(int sta,int x,int y)
{
    node now(x,y,sta,0);
    p.push(now);
    memset(vis,false,sizeof(vis));
    vis[x][y][sta]=true;
    int ans,cnt=0;
    while(!p.empty())
    {
        now=p.front();
        p.pop();
        ff(i,0,3)
        {
            int temp,nt,xx,yy,sta1=now.st%2,sta2=(now.st>>1);
            xx=now.posx+dx[i];
            yy=now.posy+dy[i];
            if(!check(xx,yy))
               continue;
            //cout << xx << " " << yy << endl;
            int pan=sta1;
            if(pan)
            {
                nt=now.ti;
                temp=(sta2<<1);
            }
            else
            {
                nt=now.ti+1;
                temp=now.st;
            }
            if(s[xx][yy]=='.'||s[xx][yy]=='S')
            {
                if(!vis[xx][yy][temp])
                {
                    vis[xx][yy][temp]=true;
                    p.push(node(xx,yy,temp,nt));
                }
            }
            else if(s[xx][yy]=='P')
            {
                if(!vis[xx][yy][temp+1])
                {
                    vis[xx][yy][temp+1]=true;
                    p.push(node(xx,yy,temp+1,nt));
                }
            }
            else if(s[xx][yy]=='B')
            {
                sta2=(sta2<<1)+1;
                sta2%=32;
                sta2=sta2<<1;
                temp=sta2|temp;
                if(!vis[xx][yy][temp])
                {
                    vis[xx][yy][temp]=true;
                    p.push(node(xx,yy,temp,nt));
                }
            }
            else if(s[xx][yy]=='#')
            {
                if(sta2%2)
                {
                    nt++;
                    sta2=sta2>>1;
                    temp=sta2<<1;
                    if(!vis[xx][yy][temp])
                    {
                        vis[xx][yy][temp]=true;
                        p.push(node(xx,yy,temp,nt));
                    }
                }
            }
            else if(s[xx][yy]=='T')
            {
                if(cnt==0)
                {
                    ans=nt;
                    cnt++;
                }
                else if(ans!=nt)
                {
                    ans=min(nt,ans);
                }
            }
        }
    }
    while(!p.empty())
        p.pop();
    if(cnt==0)
        printf("-1\n");
    else
        printf("%d\n",ans);
}
int main()
{
    //freopen("out.txt", "w", stdout);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        ff(i,1,n)
        scanf("%s",s[i]+1);
        //ff(i, 1, n) printf("%s\n", s[i]+1);
        int x,y;
        ff(i,1,n)
        ff(j,1,m)
        if(s[i][j]=='S')
        {
            x=i;
            y=j;
            break;
        }
        work(0,x,y);
    }
    return 0;
}
