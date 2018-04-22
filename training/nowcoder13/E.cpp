#include <bits/stdc++.h>
#include <stdio.h>
#define ff(i,x,y)for(int i=x;i<y+1;i++)
#define fs(i,x,y)for(int i=x;i>y-1;i--)
#define all(x) x.begin(),x.end()
#define Ins(x) inserter(x,x.begin())
using namespace std;
typedef long long ll;
char s[110];
int n,dp0[110][55][2],dp1[110][55][2],len;
int main()
{
    scanf("%s",s+1);
    scanf("%d",&n);
    len=strlen(s+1);
    ff(i,0,len)
    {
        ff(j,0,n)
        {
            dp1[i][j][0]=dp1[i][j][1]=-1e7;
            dp0[i][j][0]=dp0[i][j][1]=1e7;
        }
    }
    dp1[0][0][1]=dp0[0][0][1]=0;
    ff(i,0,len-1)
    {
        ff(j,0,n)
        {
            ff(k,0,n-j)
            {
                    if((s[i+1]=='F'&&(k%2)==0)||((s[i+1]=='T'&&(k%2)==1)))
                    {
                        dp1[i+1][j+k][1]=max(dp1[i+1][j+k][1],dp1[i][j][1]+1);
                        dp1[i+1][j+k][0]=max(dp1[i+1][j+k][0],dp1[i][j][0]-1);
                        dp0[i+1][j+k][1]=min(dp0[i+1][j+k][1],dp0[i][j][1]+1);
                        dp0[i+1][j+k][0]=min(dp0[i+1][j+k][0],dp0[i][j][0]-1);
                    }
                    else
                    {
                        dp1[i+1][j+k][1]=max(dp1[i+1][j+k][1],dp1[i][j][0]);
                        dp1[i+1][j+k][0]=max(dp1[i+1][j+k][0],dp1[i][j][1]);
                        dp0[i+1][j+k][1]=min(dp0[i+1][j+k][1],dp0[i][j][0]);
                        dp0[i+1][j+k][0]=min(dp0[i+1][j+k][0],dp0[i][j][1]);
                    }
            }
        }
    }
    int ans=0;
    ans=max(dp1[len][n][0],dp1[len][n][1]);
    ans=max(-dp0[len][n][0],ans);
    ans=max(-dp0[len][n][1],ans);
    printf("%d",ans);
    return 0;
}
