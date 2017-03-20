#include <cstdio>
#include <cstring>
char s[10000];
int scnt[100000],cnt=0;
int main()
{
    memset(scnt,0,sizeof(scnt));
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)scnt[s[i]]++;
    for(int i='a';i<='z';i++)if(scnt[i])cnt++;
    if(cnt%2==0)printf("CHAT WITH HER!\n");
    else printf("IGNORE HIM!\n");
    return 0;
}
