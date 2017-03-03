#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define MN 10
using namespace std;

struct Com
{
    int r,c,dir;
    Com(int r=0,int c=0,int dir=0):r(r),c(c),dir(dir){}
};
const char* dirs="NESW";
const char* turns="FLR";

int dir_id(char c){return strchr(dirs,c)-dirs; }
int turn_id(char c){return strchr(turns,c)-turns; }

const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};

int r0,c0,r1,c1,r2,c2,dir,access[MN][MN][4][3],d[MN][MN][4];
Com pre[MN][MN][4];

bool Read()
{
    char s1[100],s2[100];
    if(scanf("%s%d%d%s%d%d",s1,&r0,&c0,s2,&r2,&c2)!=6)return false;
    memset(access,0,sizeof(access));
    printf("%s\n",s1);
    dir=dir_id(s2[0]);
    r1=r0+dr[dir];c1=c0+dc[dir];
    while(true)
    {
        int r,c;
        char s3[100];
        scanf("%d",&r);
        if(r==0)break;
        scanf("%d",&c);
        while(true)
        {
            scanf("%s",s3);
            if(s3[0]=='*')break;
            for(int i=1;i<strlen(s3);i++)
            {
                access[r][c][dir_id(s3[0])][turn_id(s3[i])]=1;
            }
        }
    }
    return true;
}

void PrintAns(Com u)
{
    vector<Com> ans;
    while(true)
    {
        ans.push_back(u);
        if(d[u.r][u.c][u.dir]==0)break;
        u=pre[u.r][u.c][u.dir];
    }
    int cnt=0;
    ans.push_back(Com(r0,c0,dir));
    for(int i=ans.size()-1;i>=0;i--)
    {
        if(cnt%10==0)printf(" ");
        printf(" (%d,%d)",ans[i].r,ans[i].c);
        if(++cnt%10==0)printf("\n");
    }
    if(ans.size()%10!=0) printf("\n");
}

Com Walk(const Com &u,int turn)
{
    int dir=u.dir;
    if(turn==1)dir=(dir+3)%4;
    if(turn==2)dir=(dir+1)%4;
    return Com(u.r+dr[dir],u.c+dc[dir],dir);
}

bool Judge(int r,int c)
{
    return r>=1&&r<=9&&c>=1&&c<=9;
}

void Bfs()
{
    queue<Com> Q;
    Com begin(r1,c1,dir);
    memset(d,-1,sizeof(d));
    d[r1][c1][dir]=0;
    Q.push(begin);
    while(!Q.empty())
    {
        Com u=Q.front();Q.pop();
        if(u.r==r2&&u.c==c2)
        {
            PrintAns(u);
            return;
        }
        for(int i=0;i<3;i++)
        {
            Com v=Walk(u,i);
            if(access[u.r][u.c][u.dir][i]&&Judge(v.r,v.c)&&d[v.r][v.c][v.dir]<0)
            {
                d[v.r][v.c][v.dir]=d[u.r][u.c][u.dir]+1;
                pre[v.r][v.c][v.dir]=u;
                Q.push(v);
            }
        }
    }
    printf("  No Solution Possible\n");
}

int main()
{
    while(Read())
    {
        Bfs();
    }
    return 0;
}
