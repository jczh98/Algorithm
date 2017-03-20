#include <cstdio>
#include <cstring>
#include <cctype>
char s[10000];
int main()
{
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='H'||s[i]=='Q'||s[i]=='9')
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

