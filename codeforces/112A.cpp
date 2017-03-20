#include <cstdio>
#include <cstring>
#include <cctype>
char s1[1000],s2[1000];
int len;
int main()
{
    scanf("%s%s",s1,s2);
    len=strlen(s1);
    for(int i=0;i<len;i++)s1[i]=tolower(s1[i]),s2[i]=tolower(s2[i]);
    for(int i=0;i<len;i++)
    {
        if(s1[i]-s2[i]>0)
        {
            printf("1\n");
            return 0;
        }else if(s1[i]-s2[i]<0)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
