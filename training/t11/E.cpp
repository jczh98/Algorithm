#include <bits/stdc++.h>
using namespace std;
int t,h,w,n;
char mp[300][300];
bool Solve()
{
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            mp[i][j]='.';
        }
    }
    int spot=0,start;
    for(int i=2;i<h;i++)
    {
        if(i&1)start=3;else start=2;
        for(int j=start;j<w;j+=2)
        {
            mp[i][j]='#';
            spot++;
            if(spot>=n)return true;
        }
    }
    return false;
}
int main()
{
    freopen("figure.in","r",stdin);
    freopen("figure.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&h,&w,&n);
        if(Solve())
        {
            for(int i=1;i<=h;i++)
            {
                for(int j=1;j<=w;j++)
                {
                    printf("%c",mp[i][j]);
                }printf("\n");
            }
        }else
        {
            printf("Impossible\n");
        }
        printf("\n");
    }
    return 0;
}
