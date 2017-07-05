#include <bits/stdc++.h>
#define MN 100
using namespace std;
int n,m,cnt[MN];
int main()
{
    scanf("%d%d",&n,&m);
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=m;i++)
    {
        int a;int b;
        scanf("%d%d",&a,&b);
        cnt[a]++,cnt[b]++;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",cnt[i]);
    }
    return 0;
}
