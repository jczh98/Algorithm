#include <bits/stdc++.h>
#define N 1010
#define INF INT_MAX
using namespace std;
int n,x[N],y[N],s[N][N],f[N][N];
int CalW(int i,int j,int k){return x[k+1]-x[i]+y[k]-y[j];}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
        /*for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=i+1;k<j;k++)
                {
                    w[i][j]=p[k+1].x-p[i].x+p[k].y-p[j].y;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",w[i][j]);
            }printf("\n");
        }*/
        memset(s,0,sizeof(s));
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)s[i][i]=i;
        for(int len=2;len<=n;len++)
        {
            for(int i=1;i<=n-len+1;i++)
            {
                int j=i+len-1;f[i][j]=INF;
                for(int k=s[i][j-1];k<=min(s[i+1][j],j-1);k++)
                {
                    if(f[i][j]>f[i][k]+f[k+1][j]+CalW(i,j,k))
                    {
                        f[i][j]=f[i][k]+f[k+1][j]+CalW(i,j,k);s[i][j]=k;
                    }
                }
            }
        }
        printf("%d\n",f[1][n]);
    }
    return 0;
}
