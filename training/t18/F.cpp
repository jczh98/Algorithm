#include <bits/stdc++.h>
using namespace std;
int t,width,height;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&width,&height);
        if(width==height)printf("Square\n");
        else printf("Rectangle\n");
    }
    return 0;
}
