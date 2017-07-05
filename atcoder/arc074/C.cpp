#include <bits/stdc++.h>
using namespace std;
int h,w;
int main()
{
    scanf("%d%d",&h,&w);
    if(h>w)swap(h,w);
    if(h%3==0||w%3==0)printf("0\n");
    else
    {
        long long ans=1e10+7,s1,s2,s3;
        for(int i=1;i<=w/2+1;i++)
        {
            s1=(long long)h*(long long)i;s2=(long long)h*(long long)((w-i)/2);s3=(long long)h*(long long)((w-i)-(w-i)/2);
            ans=min(ans,max(s1,max(s2,s3))-min(s1,min(s2,s3)));
        }
        for(int i=1;i<=h/2+1;i++)
        {
            s1=(long long)w*(long long)i;s2=(long long)(h-i)*(long long)(w/2);s3=(long long)(h-i)*(long long)(ceil((double)w/2));
            ans=min(ans,max(s1,max(s2,s3))-min(s1,min(s2,s3)));
        }
        for(int i=1;i<=w/2+1;i++)
        {
            s1=(long long)h*(long long)i;s2=(long long)(h/2)*(long long)(w-i);s3=(long long)(ceil((double)h/2))*(long long)(w-i);
            ans=min(ans,max(s1,max(s2,s3))-min(s1,min(s2,s3)));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
