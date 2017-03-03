#include <cstdio>
#include <iostream>
#include <cstring>
#define MAXN 100100
using namespace std;

int sum[MAXN],kase=1;

void Build(int p)
{
    int u;scanf("%d",&u);
    if(u==-1)return;
    sum[p]+=u;
    Build(p-1);Build(p+1);
}

int Input()
{
    int u;
    scanf("%d",&u);
    if(u==-1)return false;
    memset(sum,0,sizeof sum);
    int root=MAXN/2;
    sum[root]+=u;
    Build(root-1);Build(root+1);
    return true;
}

int main()
{
    while(Input())
    {
        int p=0;while(sum[p]==0)p++;
        printf("Case %d:\n%d",kase++,sum[p++]);
        while(sum[p]!=0)printf(" %d",sum[p++]);
        printf("\n\n");
    }
    return 0;
}
