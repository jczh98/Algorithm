#include <bits/stdc++.h>
using namespace std;
int t,capital,year,d,v[50],in[50],ans,f[100000],temp,i,j,w;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&capital,&year,&d);
        for(i=1;i<=d;i++)
        {
            scanf("%d%d",&v[i],&in[i]);
            v[i]/=1000;
        }
        ans=capital;
        for(i=1;i<=year;i++)
        {
            temp=ans/1000;
            for(int i=0;i<=temp;i++)f[i]=0;
            for(j=1;j<=d;j++)
            {
                for(w=v[j];w<=temp;w++)
                {
                    f[w]=max(f[w],f[w-v[j]]+in[j]);
                }
            }
            ans+=f[temp];
        }
        printf("%d\n",ans);
    }
    return 0;
}

