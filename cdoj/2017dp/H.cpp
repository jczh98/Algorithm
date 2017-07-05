#include <bits/stdc++.h>
#define N 1100
using namespace std;
int n,m,a[N][N];
long long f1[N][N],f2[N][N],f3[N][N],f4[N][N],ans=0,t;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)f1[i][j]=max(f1[i-1][j]+a[i][j],f1[i][j-1]+a[i][j]);
    //cout<<endl;for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%d ",f1[i][j]);cout<<endl;}
    for(int i=n;i>=1;i--)for(int j=1;j<=m;j++)f2[i][j]=max(f2[i+1][j]+a[i][j],f2[i][j-1]+a[i][j]);
    //cout<<endl;for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%d ",f2[i][j]);cout<<endl;}
    for(int i=n;i>=1;i--)for(int j=m;j>=1;j--)f3[i][j]=max(f3[i+1][j]+a[i][j],f3[i][j+1]+a[i][j]);
    //cout<<endl;for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%d ",f3[i][j]);cout<<endl;}
    for(int i=1;i<=n;i++)for(int j=m;j>=1;j--)f4[i][j]=max(f4[i-1][j]+a[i][j],f4[i][j+1]+a[i][j]);
    //cout<<endl;for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)printf("%d ",f4[i][j]);cout<<endl;}
    for(int i=2;i<=n-1;i++)for(int j=2;j<=m-1;j++)
    {
        ans=max(ans,max(f1[i][j-1]+f2[i+1][j]+f3[i][j+1]+f4[i-1][j],f1[i-1][j]+f2[i][j-1]+f3[i+1][j]+f4[i][j+1]));
    }
    printf("%lld\n",ans);
    return 0;
}
