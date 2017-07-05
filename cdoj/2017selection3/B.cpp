#include <bits/stdc++.h>
using namespace std;
int n,ans=600;
double T,w[1100];
int cmp(double x,double y){return x>y;}
int main()
{
    scanf("%lf%d",&T,&n);
    for(int i=1;i<=n;i++)scanf("%lf",&w[i]);
    sort(w+1,w+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        for(int cut=1;cut<=ans;cut++)
        {
            if(cut*i>=ans)break;
            double mx=w[i]/cut;int cnt=0,flag=0;
            for(int j=1;j<=n;j++)
            {
                if(cnt>ans)break;
                int t=(int)ceil(w[j]/mx);
                if(w[j]/t<=mx*T){flag=1;break;}
                cnt+=t-1;
            }
            if(!flag&&cnt<ans)ans=cnt;
        }
    }
    printf("%d\n",ans);
    return 0;
}
