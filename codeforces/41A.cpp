#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[10000],t[10000];
int main()
{
    scanf("%s%s",s,t);
    for(int i=0;i<strlen(s)/2;i++)swap(s[i],s[strlen(s)-i-1]);
    printf("%s\n",strcmp(s,t)==0?"YES\n":"NO\n");
    return 0;
}
