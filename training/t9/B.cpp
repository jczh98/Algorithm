#include <bits/stdc++.h>
using namespace std;
long long n,m,g[300][300],dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
char t;
long long ans=0;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(cin>>n>>m)
    {
        memset(g,0,sizeof(g));
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>t;
                g[i][j]=t-'0';
            }
        }
        //cout<<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(g[i][j])ans=ans+(4*g[i][j]+2);
                for(int k=0;k<4;k++)ans-=min(g[i+dx[k]][j+dy[k]],g[i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
