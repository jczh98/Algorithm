#include <bits/stdc++.h>
using namespace std;
int n,a[1000];
double b[1000],c[1000],ans=1e9;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);b[i]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            double d=(double)(a[j]-a[i])/(j-i),t=0;
            b[i]=a[i];b[j]=a[j];
            for(int x=i-1;x>=1;x--)b[x]=b[x+1]-d;
            for(int x=i+1;x<=n;x++)b[x]=b[x-1]+d;
            for(int x=1;x<=n;x++)t+=fabs(b[x]-a[x]);
            //cout<<t<<endl;
            //for(int x=1;x<=n;x++)printf("%f ",b[x]);cout<<endl;
            if(ans>t)
            {
                ans=t;
                memcpy(c,b,sizeof(b));
            }
        }
    }
    printf("%.4f\n",ans);
    for(int i=1;i<n;i++)
    {
        printf("%.7f ",c[i]);
    }
    printf("%.7f\n",c[n]);
    return 0;
}
