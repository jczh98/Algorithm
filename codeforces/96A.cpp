#include <cstdio>
#include <cstring>
int cnt;
char s[100000000];
int main()
{
    scanf("%s",&s);
    cnt=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='0')cnt++;
        else
        {
            if(cnt>=7)
            {
                printf("YES\n");
                return 0;
            }
            cnt=0;
        }
    }
    if(cnt>=7)
    {
        printf("YES\n");
        return 0;
    }
    cnt=0;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='1')cnt++;
        else
        {
            if(cnt>=7)
            {
                printf("YES\n");
                return 0;
            }
            cnt=0;
        }
    }
    if(cnt>=7)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}
