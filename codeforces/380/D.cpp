#include <cstdio>
#include <cstring>
#define MN 550000

int n,a,b,k,ans[MN],cnt,tot;
char s[MN];

int main()
{
    scanf("%d%d%d%d",&n,&a,&b,&k);
    scanf("%s",s);
    tot=0;cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            cnt++;
            if(cnt==b)ans[tot++]=i,cnt=0;
        }else if(s[i]=='1')
        {
            cnt=0;
        }
    }
    printf("%d\n",tot-a+1);
    for(int i=0;i<tot-a+1;i++)printf("%d ",ans[i]+1);
    return 0;
}
