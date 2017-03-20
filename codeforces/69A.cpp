#include <cstdio>
int n,x,y,z,sx=0,sy=0,sz=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d%d",&x,&y,&z),sx+=x,sy+=y,sz+=z;
    if(sx==0&&sy==0&&sz==0)printf("YES\n");
    else printf("NO\n");
    return 0;
}
