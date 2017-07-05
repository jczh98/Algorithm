#include <bits/stdc++.h>
using namespace std;
int r,g,b;
int main()
{
    scanf("%d%d%d",&r,&g,&b);
    int tot=r*100+g*10+b;
    if(tot%4)printf("NO\n");
    else printf("YES\n");
    return 0;
}
