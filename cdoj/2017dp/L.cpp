#include <bits/stdc++.h>
#define N 5
#define MOD (LL)1e9+7
using namespace std;
typedef long long LL;
LL f[2][1<<5];
int n,m,cur=0;
int main()
{
    scanf("%d%d",&n,&m);
    if(n<m)swap(n,m);
    memset(f,0,sizeof(f));
    f[0][(1<<m)-1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cur^=1;
            memset(f[cur],0,sizeof(f[cur]));
            int r=(1<<m)-1;
            for(int k=0;k<(1<<m);k++)
            {
                if(k&(1<<(m-1)))f[cur][(k<<1)&r]+=f[cur^1][k],f[cur][(k<<1)&r]%=MOD;//no put
                if(i>1&&!(k&(1<<(m-1))))f[cur][(k<<1)|1]+=f[cur^1][k],f[cur][(k<<1)|1]%=MOD;//up
                if(j>1&&!(k&1)&&(k&(1<<(m-1))))f[cur][((k<<1)|3)&r]+=f[cur^1][k],f[cur][((k<<1)|3)&r]%=MOD;//horizental
            }
        }
    }
    printf("%lld\n",f[cur][(1<<m)-1]);
    return 0;
}
