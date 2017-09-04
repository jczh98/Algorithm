#include <bits/stdc++.h>
using namespace std;
int t,n,k,f[5050][5050],x,y,dx,dy,ans;
char str[100];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(f,-1,sizeof(f));
        scanf("%d%d",&n,&k);
        for(int i=0;i<(1<<(k-1));i++)f[1][i]=0;
        for(int i=(1<<(k-1));i<(1<<k);i++)f[1][i]=1;
        for(int i=2;i<=n;i++)
        {
            scanf("%s%d%s%s",str,&x,str,str);
            if(str[0]=='P')
            {
                scanf("%d%s%s%s",&x,str,str,str);
                if(str[0]=='g')dx=1;else dx=0;
                for(int j=0;j<(1<<k);j++)
                {
                    if((j>>(x-i+k)&1)==dx)f[i][(j+(1<<k))>>1]=max(f[i][(j+(1<<k))>>1],f[i-1][j]+1);
                    f[i][j>>1]=max(f[i][j>>1],f[i-1][j]);
                }
                scanf("%s",str);
            }else
            {
                scanf("%s%d%s%s%s",str,&x,str,str,str);
                if(str[0]=='g')dx=1;else dx=0;
                scanf("%s%s%d%s%s%s",str,str,&y,str,str,str);
                if(str[0]=='g')dy=1;else dy=0;
                for(int j=0;j<(1<<k);j++)
                {
                    if(!((((j>>(x-i+k))&1)==dx)&&(((j>>(y-i+k))&1)!=dy)))
                    {
                        f[i][(j+(1<<k))>>1]=max(f[i][(j+(1<<k))>>1],f[i-1][j]+1);
                    }
                    f[i][j>>1]=max(f[i][j>>1],f[i-1][j]);
                }
                scanf("%s",str);
            }
        }
        ans=0;
        for(int i=0;i<(1<<k);i++)ans=max(ans,f[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
