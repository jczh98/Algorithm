#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<vector<LL> > Mat;
const LL MOD=1000000009LL;
LL n;
Mat A={{1,3,0,0,0},
{0,0,1,1,2},
{0,0,1,1,2},
{1,3,0,0,0},
{0,0,1,1,1}};
Mat f={{4,12,12,12,24}};
Mat Clear(Mat mat)
{
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            mat[i][j]=0;
        }
    }
    return mat;
}
Mat Init(Mat mat)
{
    Clear(mat);
    for(int i=0;i<mat.size();i++)
    {
        mat[i][i]=1;
    }
    return mat;
}
Mat Multiply(Mat mat1,Mat mat2)
{
    Mat mat(mat1.size(),vector<LL>(mat2[0].size()));
    Clear(mat);
    for(int i=0;i<mat1.size();i++)
    {
        for(int j=0;j<mat2.size();j++)
        {
            for(int k=0;k<mat2[0].size();k++)
            {
                mat[i][j]=(mat[i][j]+(mat1[i][k]%MOD)*(mat2[k][j]%MOD))%MOD;
            }
        }
    }
    return mat;
}
Mat MatQuickPow(Mat a,LL b)
{
    Mat res(a.size(),vector<LL>(a[0].size()));res=Init(res);
    while(b)
    {
        if(b&1)res=Multiply(res,a);
        a=Multiply(a,a);
        b>>=1;
    }
    return res;
}
LL QuickPow(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1)res=((res%MOD)*(a%MOD))%MOD;
        a=((a%MOD)*(a%MOD))%MOD;
        b>>=1;
    }
    return res;
}
int main()
{

    cin>>n;
    Mat res=MatQuickPow(A,n-3);
    LL tot=QuickPow(4,n);
    Mat ans=Multiply(f,res);
    LL cnt=0;
    for(int i=0;i<ans[0].size();i++)cnt=(ans[0][i]%MOD+cnt)%MOD;
    cout<<(tot%MOD-cnt%MOD+MOD)%MOD<<endl;
    return 0;
}
