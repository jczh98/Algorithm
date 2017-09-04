#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t,a,b,n,p,f[10][300],ans;
int number[1001000];
int main()
{
    cin>>t;
    while(t--)
    {
        memset(f,0,sizeof(f));
        ans=0;
        cin>>a>>b>>n>>p;
        while(a>b)a-=b;
        if(a==b)a=1,b=1;
        for(int i=1;i<=n;i++)
        {
            number[i]=a*10/b;
            a=a*10%b;
        }
        /*for(int i=1;i<=n;i++)
        {
            cout<<number[i];
        }*/
        f[0][0]=0;
        int pre=0;
        for(int i=1;i<=n;i++)
        {
            memset(f[pre^1],0,sizeof(f[pre^1]));
            for(int j=0;j<=p;j++)
            {
                f[pre^1][(j*10+number[i])%p]+=f[pre][j];
            }
            f[pre^1][number[i]%p]+=1;
            ans+=f[pre^1][0];
            pre^=1;
        }
        cout<<ans<<endl;
    }
}
