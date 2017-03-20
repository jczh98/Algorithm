#include <cstdio>
#include <cstring>
char s[200200];
int n,ans=0;
int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)if(s[i]=='<')ans++;else break;
    for(int i=n-1;i>=0;i--)if(s[i]=='>')ans++;else break;
    printf("%d\n",ans);
    return 0;
}
