#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
char s[10000];
int cnt[10000],k=0;
int main()
{
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='1'&&s[i]<='3')cnt[k++]=s[i]-'1'+1;
    }
    sort(cnt,cnt+k);
    for(int i=0;i<k-1;i++)printf("%d+",cnt[i]);
    printf("%d\n",cnt[k-1]);
    return 0;
}
