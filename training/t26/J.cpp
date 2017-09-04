#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a[100100],vis[100100],s[100100];
int main()
{
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    int n;
    cin >> n;
    int pos,len=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=2*n;i++)
    {
        cin >> a[i];
        s[i]=(s[i-1]+a[i])%n;
        if(len > 1) continue;
        int mod=s[i];
        if(mod==0)
        {
            pos=1,len=i;
            continue;
        }
        if(vis[mod]==0)
        {
            vis[mod]=i;
        }
        else
        {
            len=i-vis[mod];
            pos=vis[mod]+1;
        }
    }
    if(!len) printf("IMPOSSIBLE\n");
    else {
        std::sort(a+pos,a+pos+len);
        for(int i=pos;i<pos+len-1;i++) printf("%d ",a[i]);
        printf("%d\n",a[pos+len-1]);
    }
    return 0;
}

