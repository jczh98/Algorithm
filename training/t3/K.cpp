#include <cstdio>
#include <cstring>
using namespace std;
int w,h,sg[300][300],s[10000];
int Dfs(int W,int H)
{
    if(sg[W][H]!=-1)return sg[W][H];
    memset(s,0,sizeof(s));
    for(int i=2;i<=W/2;i++)
    {
        s[Dfs(W-i,H)^Dfs(i,H)]=1;
    }
    for(int i=2;i<=H/2;i++)
    {
        s[Dfs(W,H-i)^Dfs(W,i)]=1;
    }
    int mex=0;
    while(s[mex])mex++;
    return sg[W][H]=sg[H][W]=mex;
}
int main()
{
    memset(sg,-1,sizeof(sg));
    sg[2][2]=sg[3][2]=sg[2][3]=sg[3][3]=0;
    while(scanf("%d%d",&w,&h)==2)
    {
        int ans=Dfs(w,h);
        if(!ans) printf("LOSE\n");
        else printf("WIN\n");
    }
    return 0;
}
