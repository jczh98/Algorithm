#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t,n,number;
LL C[100][100],f[100];
int main()
{
    C[1][0]=C[1][1]=1;
    for(int i=2;i<=50;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=50;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1]);
    }
    f[1]=1;f[2]=2;f[3]=4;
    for(int i=4;i<=20;i++)
    {
        f[i]+=f[i-1];
        for(int j=1;j<i-1;j++)
        {
            if(j==1||i-j-1==1)
            {
                f[i]+=((f[j]*f[i-j-1]/2)*C[i-1][j]);
            }else f[i]+=((f[j]/2)*(f[i-j-1]/2)*C[i-1][j]);
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&number,&n);
        cout<<number<<" "<<f[n]<<endl;
    }
    return 0;
}
