#include <bits/stdc++.h>
#define MN 10000
using namespace std;
int n,cnt_red=1,cnt_blue=1,red[MN],blue[MN],ans=0;
int cmp(int a,int b)
{
    return a>b;
}
char str[MN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        int len=strlen(str);
        if(str[len-1]=='R')
        {
            red[cnt_red++]=atoi(str);
        }else
        {
            blue[cnt_blue++]=atoi(str);
        }
    }
    //for(int i=1;i<cnt_red;i++)cout<<red[i]<<endl;
    sort(red+1,red+cnt_red,cmp);
    sort(blue+1,blue+cnt_blue,cmp);
    int mx=min(cnt_blue,cnt_red);
    if(mx==1)
    {
        printf("0\n");
        return 0;
    }
    for(int i=1;i<mx;i++)
    {
        ans+=(red[i]+blue[i]);
    }
    ans-=(mx-1)*2;
    printf("%d\n",ans);
    return 0;
}
