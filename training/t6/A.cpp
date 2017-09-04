#include <bits/stdc++.h>
using namespace std;
char str[100100];
int cnt0=0,cnt1=0;
int main()
{
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='0')cnt0++;
        else if(str[i]=='1')cnt1++;
    }
    printf("%d\n",min(cnt0,cnt1));
    return 0;
}
