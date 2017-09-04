#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL f[10000][10000]={0};
int N=4,M=30;
int main()
{
    f[1][1]=f[1][2]=1;
    for(int i=3;i<=M;i++)f[1][i]=f[1][i-1]+2*f[1][i-2];
    for(int i=2;i<=M;i++)
    {
        for(int j=1;j<=M-N;j++)
        {
            for(int k=j;k<=j+N-1;k++)
            {
                f[i][j]+=f[i-1][k];
            }
        }
    }
    for(int i=1;i<=M;i++)
    {
        for(int j=1;j<=M-N;j++)
        {
            printf("%d ",f[i][j]);
        }cout<<endl;
    }
}
