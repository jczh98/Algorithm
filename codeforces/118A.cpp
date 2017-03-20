#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
char s[1000000],ss[100000];
int cnt=0;
int main()
{
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='A'||s[i]=='O'||s[i]=='Y'||s[i]=='E'||s[i]=='U'||s[i]=='I'||s[i]=='a'||s[i]=='o'||s[i]=='y'||s[i]=='e'||s[i]=='u'||s[i]=='i')continue;
        ss[cnt++]=s[i];
    }
    for(int i=0;i<cnt;i++)printf(".%c",tolower(ss[i]));
    printf("\n");
    return 0;
}
