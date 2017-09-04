#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
LL n,t,f[3000][3000];
int main()
{
    f[1][1]=26;
    for(int i=2;i<=2020;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(j==1||j==2) f[i][j+1]=(f[i-1][j]+f[i][j+1])%MOD;
            f[i][1]=(f[i][1]+f[i-1][j]*25)%MOD;
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==0)
        {
            cout<<0<<endl;
            continue;
        }else if(n==1)
        {
            cout<<26<<endl;
            continue;
        }else if(n==2)
        {
            cout<<676<<endl;
            continue;
        }
        LL sum=0;
        for(int i=1;i<=3;i++)sum=(sum+f[n][i])%MOD;
        cout<<sum<<endl;
    }
    return 0;
}
