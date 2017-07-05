#include <bits/stdc++.h>
#define MN 101
#define inf 100000000
using namespace std;
int h,b,hh[MN],bb[MN],tot,m1=0,m2=0,fh[100001],fb[100001],ans=inf;
int main()
{
    scanf("%d",&h);
    for(int i=1;i<=h;i++)scanf("%d",&hh[i]),m1+=hh[i];
    scanf("%d",&b);
    for(int i=1;i<=b;i++)scanf("%d",&bb[i]),m2+=bb[i];
    tot=min(m1,m2);
    for(int i=1;i<=tot;i++)fh[i]=inf;
    fh[0]=0;
    for(int i=0;i<=h;i++)
    {
        for(int j=tot;j>=1;j--)
        {
            if(j-hh[i]>=0)fh[j]=min(fh[j],1+fh[j-hh[i]]);
            else fh[j]=fh[j];
        }
    }
    for(int i=1;i<=tot;i++)fb[i]=inf;
    fb[0]=0;
    for(int i=1;i<=b;i++)
    {
        for(int j=tot;j>=1;j--)
        {
            if(j-bb[i]>=0)fb[j]=min(fb[j],1+fb[j-bb[i]]);
            else fb[j]=fb[j];
        }
    }
    /*for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=tot;j++)
        {
            printf("%d ",fh[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=tot;j++)
        {
            printf("%d ",fb[i][j]);
        }
        printf("\n");
    }*/
    for(int i=1;i<=tot;i++)ans=min(ans,fh[i]+fb[i]);
    if(ans==inf)printf("impossible\n");
    else printf("%d\n",ans);
    return 0;
}
