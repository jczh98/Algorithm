#include <bits/stdc++.h>
using namespace std;
int n,m,l[20],r[20],f[20][10],ans=0;
char str[20][300];
int main()
{
    memset(l,0,sizeof(l));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",str[i]);
    for(int i=1;i<=n;i++)for(int j=0;j<m+2;j++)if(str[i][j]=='1'){if(!l[n-i+1])l[n-i+1]=j;r[n-i+1]=j;}
    int cnt=0,maxn=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m+2;j++)if(str[i][j]=='1')cnt++;
        if(cnt){maxn=n-i+1;break;}
    }
    if(maxn==1)
    {
        printf("%d\n",r[maxn]);
        return 0;
    }
    f[2][0]=f[1][0]+2*r[1]+1;
    f[2][1]=f[1][0]+m+2;
    for(int i=3;i<=maxn;i++)
    {
        if(l[i-1]==0)
        {
            f[i][0]=f[i-1][0]+1;f[i][1]=f[i-1][1]+1;continue;
        }
        f[i][0]=min(f[i-1][0]+2*r[i-1]+1,f[i-1][1]+m+2);
        f[i][1]=min(f[i-1][0]+m+2,f[i-1][1]+2*m-2*l[i-1]+3);
    }
    ans=min(f[maxn][0]+r[maxn],f[maxn][1]+m-l[maxn]+1);
    printf("%d\n",ans);
    return 0;
}
