#include <cstdio>
#include <cstring>
char s[10000];
int cnt=0;
int main()
{
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)if(s[i]=='4'||s[i]=='7')cnt++;
    if(cnt==0)
    {
        printf("NO\n");
        return 0;
    }
    while(cnt)
    {
        if((cnt%10!=4)&&(cnt%10!=7))
        {
            printf("NO\n");
            return 0;
        }
        cnt/=10;
    }
    printf("YES\n");
    return 0;
}
