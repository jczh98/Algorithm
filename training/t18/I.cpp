#include <bits/stdc++.h>
using namespace std;
int t,n,a[50000],ans;
int Hamming(int x, int y) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        if ((x & (1 << i)) ^ (y & (1 << i))) {
            ++res;
        }
    }
    return res;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,Hamming(a[i],a[j]));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
