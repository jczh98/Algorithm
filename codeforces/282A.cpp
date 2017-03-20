#include <cstdio>
#include <cstring>
int n,ans=0;
char s[10000];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]=='+')
            {
                ans++;break;
            }else if(s[j]=='-')
            {
                ans--;break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
