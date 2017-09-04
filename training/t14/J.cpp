#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD=10007;
struct Mat
{
    LL a[10][10],sz;
    Mat()
    {
        sz=0;
        memset(a,0,sizeof(a));
    }
};
LL n;
Mat Multi(Mat m1,Mat m2)
{
    Mat ans=Mat();
    ans.sz=m1.sz;
    for(int i=1;i<=m1.sz;i++)
        for(int j=1;j<=m2.sz;j++)
            if(m1.a[i][j])
                for(int k=1;k<=m1.sz;k++)
                    ans.a[i][k]=(ans.a[i][k]+m1.a[i][j]*m2.a[j][k])%MOD;

    return ans;
}
Mat MatQuickPow(Mat m,int n)
{
    Mat ans=Mat();
    for(int i=1;i<=m.sz;i++)ans.a[i][i]=1;
    ans.sz=m.sz;
    while(n)
    {
        if(n&1)ans=Multi(m,ans);
        m=Multi(m,m);
        n>>=1;
    }
    return ans;
}
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        Mat ans=Mat();
        ans.sz=3;
        ans.a[1][1]=2;
        ans.a[1][2]=1;
        ans.a[1][3]=0;
        ans.a[2][1]=2;
        ans.a[2][2]=2;
        ans.a[2][3]=2;
        ans.a[3][1]=0;
        ans.a[3][2]=1;
        ans.a[3][3]=2;
        ans=MatQuickPow(ans,n);
        cout<<ans.a[1][1]<<endl;
    }
    return 0;
}


