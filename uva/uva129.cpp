#include <cstdio>
#include <cstring>
#include <iostream>
#define MN 1000
using namespace std;

int n,L,cnt;
char s[MN];

bool Dfs(int cur)
{
    if(cnt++==n)
    {
        for(int i=0;i<cur;i++)
        {
            if(i%64==0&i>0)printf("\n");
            else if(i%4==0&i>0)printf(" ");
            printf("%c",s[i]+'A');
        }
        printf("\n%d\n",cur);
        return 1;
    }
    for(int i=0;i<L;i++)
    {
        s[cur]=i;
        int flag=0,eq;
        for(int j=1;j*2<=cur+1;j++)
        {
            eq=1;
            for(int k=0;k<j;k++)
            {
                if(s[cur-k]!=s[cur-k-j])
                {
                    eq=0;break;
                }
            }
            if(eq)
            {
                flag=1;break;
            }
        }
        if(!flag) if(Dfs(cur+1)) return 1;
    }
    return 0;
}

int main()
{
    while(scanf("%d%d",&n,&L))
    {
        if(n==0&&L==0)return 0;
        memset(s,0,sizeof(s));cnt=0;
        Dfs(0);
    }
    return 0;
}
