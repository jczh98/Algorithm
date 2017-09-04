#include <bits/stdc++.h>
using namespace std;
int t,n,number,sz=1005;
double l,r,s,f[5000][5000],ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%lf%lf",&number,&n,&l,&r);
        memset(f,0,sizeof(f));
        s=1.0-l-r;ans=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j)f[i][j]=f[i-1][j-1]*r+f[i-1][min(j+1,i-1)]*l+f[i-1][min(j,i-1)]*s;
                else f[i][j]=f[i-1][min(j+1,i-1)]*l+f[i-1][min(j,i-1)]*s;
            }
            f[i][i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            ans+=i*(f[n][i]-f[n][i-1]);
        }
        printf("%d %.4f\n",number,ans);
    }
    return 0;
}
