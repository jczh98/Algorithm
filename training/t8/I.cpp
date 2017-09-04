#include <bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main()
{
    scanf("%d%d%d",&a[1],&a[2],&a[3]);
    scanf("%d%d%d",&b[1],&b[2],&b[3]);
    sort(a+1,a+1+3);
    sort(b+1,b+1+3);
    int width=a[1],height=a[2];
    if((a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3]&&a[1]*a[1]+a[2]*a[2]==a[3]*a[3])||(b[2]==b[1]&&b[1]*b[1]==width*width+height*height&&(b[3]==2*width||b[3]==2*height)))
    {
        printf("YES\n");
    }else
    {
        printf("NO\n");
    }
    return 0;
}
