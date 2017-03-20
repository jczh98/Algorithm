#include <cstdio>
#include <cstring>
int n,ans;
char s[100000];
int main()
{
    scanf("%d%s",&n,&s);
    int last=0,next=0;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            next=i+1;
        }else
        {
            ans+=next-last;
            last=next=i+1;
        }
    }
    ans+=next-last;
    printf("%d\n",ans);
    return 0;
}
