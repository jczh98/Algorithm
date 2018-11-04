#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;
typedef unsigned long long ULL;


typedef vector<LL> vec;
typedef vector<vec> mat;

// A*B
mat mul(mat& A, mat& B)
{
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < (int)A.size(); ++i)
        for(int j = 0; j < (int)B[0].size(); ++j)
            for(int k = 0; k < (int)B.size(); ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
    return C;
}

// A^n
mat pow(mat A, int n)
{
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < (int)A.size(); ++i) B[i][i] = 1;
    while(n)
    {
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int n,m;
LL dp[1<<5][1<<5];
void dfs(int c,int pre,int now){
    if(c>n)return ;
    if(c==n){
        dp[pre][now]++;
        return ;
    }
    dfs(c+1,pre<<1,now<<1|1);
    dfs(c+1,pre<<1|1,now<<1);
    dfs(c+2,pre<<2,now<<2);
}


int main()
{
        cin>>m>>n;
        mat a(1<<n,vec(1<<n));
        dfs(0,0,0);
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<(1<<n);j++){
                a[i][j]=dp[i][j];
                //cout<<a[i][j];
            }
            //cout<<endl;
        }
        a=pow(a,m+1);
        printf("%lld\n",a[0][(1<<n)-1]);
}