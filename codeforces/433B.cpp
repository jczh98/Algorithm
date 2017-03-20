#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int n,m;
LL v[1000100],sumv[1000100],sumu[1000100];
int main()
{
    memset(sumv,0,sizeof(sumv));
    memset(sumu,0,sizeof(sumu));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        sumv[i]=sumv[i-1]+v[i];
    }
    sort(v+1,v+1+n);
    for(int i=1;i<=n;i++)sumu[i]=sumu[i-1]+v[i];
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int q,l,r;scanf("%d",&q);
        if(q==1)
        {
            scanf("%d%d",&l,&r);
            cout<<sumv[r]-sumv[l-1]<<endl;
        }else
        {
            scanf("%d%d",&l,&r);
            cout<<sumu[r]-sumu[l-1]<<endl;
        }
    }
    return 0;
}
