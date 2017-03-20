#include <cstdio>
#include <cstring>
#include <cctype>
char s[100000];
int main()
{
    scanf("%s",s);
    int f=0;
    for(int i=1;i<strlen(s);i++)
        if(islower(s[i]))
        {
            f=1;break;
        }
    if(f)
    {
        printf("%s\n",s);
    }else
    {
        for(int i=0;i<strlen(s);i++)
        {
            if(islower(s[i]))printf("%c",toupper(s[i]));
            else printf("%c",tolower(s[i]));
        }
        printf("\n");

    }
    return 0;
}
