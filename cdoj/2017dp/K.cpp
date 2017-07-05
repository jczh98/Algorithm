#include <bits/stdc++.h>
#define N 500500
using namespace std;
typedef long long LL;
int n,m,a[N],que[N],head,tail;
LL sum[N],f[N];
LL CalX(int x,int y){return 2*sum[x]-2*sum[y];}
LL CalY(int x,int y){return f[x]+sum[x]*sum[x]-(f[y]+sum[y]*sum[y]);}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(que,0,sizeof(que));
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
        head=tail=0;f[0]=0;que[tail++]=0;
        for(int i=1;i<=n;i++)
        {
            while(head+1<tail&&CalY(que[head+1],que[head])<=sum[i]*CalX(que[head+1],que[head]))head++;
            f[i]=(sum[i]-sum[que[head]])*(sum[i]-sum[que[head]])+m+f[que[head]];
            while(head+1<tail&&CalY(i,que[tail-1])*CalX(que[tail-1],que[tail-2])<=CalY(que[tail-1],que[tail-2])*CalX(i,que[tail-1]))tail--;
            que[tail++]=i;
        }
        printf("%lld\n",f[n]);
    }
    return 0;
}
