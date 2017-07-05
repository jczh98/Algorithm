#include <bits/stdc++.h>
#define N 1100
using namespace std;
int n,m,mat[N][N],f[N][N],ans=0;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n+1;i++)for(int j=2;j<=m+1;j++)scanf("%d",&mat[i][j]);
    for(int i=0;i<=n+1;i++)for(int j=0;j<=m+1;j++)f[i][j]=-1;
    f[2][2]=mat[2][2];
    for(int i=2;i<=n+1;i++)for(int j=2;j<=m+1;j++)
    {
        if(f[i-1][j]>=0)f[i][j]=max(f[i][j],f[i-1][j]+mat[i][j]);
        if(f[i][j-1]>=0)f[i][j]=max(f[i][j],f[i][j-1]+mat[i][j]);
        if(f[i-1][j-2]>=0)f[i][j]=max(f[i][j],f[i-1][j-2]+mat[i][j]);
        if(f[i-2][j-1]>=0)f[i][j]=max(f[i][j],f[i-2][j-1]+mat[i][j]);
        ans=max(f[i][j],ans);
    }
    printf("%d\n",ans);
    return 0;
}
