#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define INF 2139062143
#define inf -2139062144
#define ll long long
using namespace std;
int t,ans;
char tmp[100],g[10][10],cur;
bool Judge()
{
    if(g[1][1]==g[1][2]&&g[1][2]==g[1][3]&&g[1][3]==cur)return true;
    if(g[2][1]==g[2][2]&&g[2][2]==g[2][3]&&g[2][3]==cur)return true;
    if(g[3][1]==g[3][2]&&g[3][2]==g[3][3]&&g[3][3]==cur)return true;

    if(g[1][1]==g[2][1]&&g[2][1]==g[3][1]&&g[3][1]==cur)return true;
    if(g[1][2]==g[2][2]&&g[2][2]==g[3][2]&&g[3][2]==cur)return true;
    if(g[1][3]==g[2][3]&&g[2][3]==g[3][3]&&g[3][3]==cur)return true;

    if(g[1][1]==g[2][2]&&g[2][2]==g[3][3]&&g[3][3]==cur)return true;
    if(g[1][3]==g[2][2]&&g[2][2]==g[3][1]&&g[3][1]==cur)return true;
    return false;
}
void Dfs(int step)
{
    if(step==4)
    {
        if(Judge())ans++;
        return ;
    }
    if(step==2)
    {
        /*for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cout<<g[i][j]<<" ";
            }cout<<endl;
        }*/
        if(Judge())
        {
            ans++;
        }
    }
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(g[i][j]=='.')
            {
                if(step&1)
                {
                    g[i][j]=cur;
                }else
                {
                    if(cur=='o')g[i][j]='x';
                    else g[i][j]='o';
                }
                Dfs(step+1);
                g[i][j]='.';
            }
        }
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                scanf("%s",tmp);
                g[i][j]=tmp[0];
            }
        }
        scanf("%s",tmp);cur=tmp[0];
        ans=0;
        if(Judge())ans++;
        Dfs(1);
        if(ans)cout<<"Kim win!"<<endl;
        else cout<<"Cannot win!"<<endl;
    }
    return 0;
}
