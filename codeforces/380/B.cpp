#include <cstdio>
#include <cstring>
#define MN 1100

int n,m,mat[MN][MN],ans=0,f;

int main()
{
    memset(mat,0,sizeof(mat));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&mat[i][j]);
    for(int i=1;i<=n;i++)
    {
        f=0;
        for(int j=1;j<=m;j++)
        {
            if(mat[i][j])f=1;
            if(!mat[i][j]&&f)ans++;
        }
        f=0;
        for(int j=m;j>=1;j--)
        {
            if(mat[i][j])f=1;
            if(!mat[i][j]&&f)ans++;
        }
    }

    for(int j=1;j<=m;j++)
    {
        f=0;
        for(int i=1;i<=n;i++)
        {
            if(mat[i][j])f=1;
            if(!mat[i][j]&&f)ans++;
        }
        f=0;
        for(int i=n;i>=1;i--)
        {
            if(mat[i][j])f=1;
            if(!mat[i][j]&&f)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
