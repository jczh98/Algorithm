#include <cstdio>
#include <cstring>
#include <cctype>
char s[10000];
int main()
{
    scanf("%s",s);
    if(islower(s[0]))s[0]=toupper(s[0]);
    printf("%s\n");
    return 0;
}
