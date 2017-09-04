#include <bits/stdc++.h>
using namespace std;
char str[1000];
int len,ans=0;
string origin;
int main()
{
    scanf("%s",str);
    len=strlen(str);
    for(int i=1;i<=len/3;i++)
    {
        origin+="PER";
    }
    for(int i=0;i<len;i++)
    {
        if(origin[i]!=str[i])ans++;
    }
    printf("%d\n",ans);
    return 0;
}
