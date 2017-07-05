#include <bits/stdc++.h>
#define M 30030
#define N 1001
using namespace std;
typedef pair<int,int> pii;
set<pii> check;
int m,k,n,p;
double f[M][10],ans=0;
int main()
{
    scanf("%d%d%d%d",&m,&k,&n,&p);
    for(int i=1;i<=k;i++)
    {
        int a,b;scanf("%d%d",&a,&b);check.insert(make_pair(a,b));
    }
    if(m==1&&k)
    {
        printf("0.000000\n");return 0;
    }else if(m==1&&k==0)
    {
        printf("1.000000\n");return 0;
    }
    f[p][0]=1.0;
    int c=0;
    for(int j=1;j<=n;j++)
    {
        c=1-c;
        for(int i=1;i<=m;i++)f[i][c]=0;
        for(int i=1;i<=m;i++)
        {
            if(check.find(make_pair(i,j))==check.end())
            {
                if(i==1&&i+1==m)f[i][c]=f[i][1-c]/2.0+f[i+1][1-c]/2.0;
                else if(i==m&&i-1==1)f[i][c]=f[i][1-c]/2.0+f[i-1][1-c]/2.0;
                else if(i-1==1&&i+1==m)f[i][c]=f[i-1][1-c]/2.0+f[i+1][1-c]/2.0+f[i][1-c]/3.0;
                else if(i-1==1&&i+1!=m)f[i][c]=f[i-1][1-c]/2.0+f[i+1][1-c]/3.0+f[i][1-c]/3.0;
                else if(i-1!=1&&i+1==m)f[i][c]=f[i-1][1-c]/3.0+f[i+1][1-c]/2.0+f[i][1-c]/3.0;
                else if(i==1&&i+1!=m)f[i][c]=f[i][1-c]/2.0+f[i+1][1-c]/3.0;
                else if(i==m&&i-1!=1)f[i][c]=f[i][1-c]/2.0+f[i-1][1-c]/3.0;
                else if(i==1&&i+1==m)f[i][c]=f[i][1-c]/2.0+f[i+1][1-c]/2.0;
                else if(i==m&&i-1==1)f[i][c]=f[i][1-c]/2.0+f[i+1][1-c]/2.0;
                else f[i][c]=f[i-1][1-c]/3.0+f[i+1][1-c]/3.0+f[i][1-c]/3.0;
            }
        }
    }
    for(int i=1;i<=m;i++)ans+=f[i][c];
    printf("%.6f\n",ans);
    return 0;
}

