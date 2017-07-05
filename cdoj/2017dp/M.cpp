#include <bits/stdc++.h>
#define N 110
#define M 50050
using namespace std;
int n,w,wt[N],v[N],c[N],f[M];
int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&wt[i],&v[i],&c[i]);
    for(int i=0;i<=w;i++)f[i]=0;
    for(int i=1;i<=n;i++)
    {
        int num=c[i];
        for(int k=1;num;k<<=1)
        {
            int mul=min(k,num);
            for(int j=w;j>=mul*wt[i];j--)
            {
                f[j]=max(f[j],f[j-mul*wt[i]]+mul*v[i]);
            }
            num-=mul;
        }
    }
    printf("%d\n",f[w]);
    return 0;
}

