#include <bits/stdc++.h>
#define MN 100100
using namespace std;
int n,w;
double expect[MN],last[MN],p[MN],t,ans;
char str[100];
int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
    {
        scanf("%s%lf%lf",str,&p[i],&t);
        expect[i]=log(1+t/w);
        if(str[0]=='s')last[i]=expect[i];
        else last[i]=last[i-1];
    }
    //for(int i=1;i<=n;i++)cout<<expect[i]<<" "<<last[i]<<endl;
    for(int i=n;i>=1;i--)
    {
        expect[i-1]=max(p[i]*expect[i]+(1-p[i])*last[i-1],expect[i-1]);
    }
    //cout<<expect[0]<<endl;
    ans=(exp(expect[0])-1)*w;
    printf("$%.2f\n",ans);
    return 0;
}
