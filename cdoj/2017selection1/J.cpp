#include <bits/stdc++.h>
using namespace std;
int n;
char str[1000];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",str);
        printf("%d\n",strlen(str));
    }
    return 0;
}
