#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
int main()
{
    scanf("%d",&n);
    int x1,y1,x2,y2;
    printf("YES\n");
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",(abs(x1)%2)+2*(abs(y1)%2)+1);
    }
    return 0;
}
