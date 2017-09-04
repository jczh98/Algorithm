#include <bits/stdc++.h>
#define eps 1e-8
#define MAXN 50005000
using namespace std;
struct Point
{
    int x,y,r;
}spark[20200];
struct Line
{
    int x,type;double y;
}line[MAXN];
int g,m,inner=0,cnt,ans=0;
int cmp(Line a,Line b)
{
    if(a.x==b.x)
    {
        if(fabs(a.y-b.y)>=eps) return a.y>b.y;
        else return a.type<b.type;
    }else return a.x<b.x;
}
int main()
{
    scanf("%d",&g);
    for(int i=1;i<=g;i++)scanf("%d%lf",&line[i].x,&line[i].y),line[i].type=1;
    cnt=g+1;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&spark[i].x,&spark[i].y,&spark[i].r);
    for(int i=1;i<=m;i++)
    {
        int r=spark[i].r;
        for(int j=spark[i].x-r;j<=spark[i].x+r;j++)
        {
            int dx=spark[i].x-j;
            line[cnt].x=j;line[cnt].y=spark[i].y*1.0+sqrt(r*r*1.0-dx*dx*1.0);line[cnt].type=0;cnt++;
            line[cnt].x=j;line[cnt].y=spark[i].y*1.0-sqrt(r*r*1.0-dx*dx*1.0);line[cnt].type=2;cnt++;
        }
    }
    sort(line+1,line+cnt,cmp);
    for(int i=1;i<cnt;i++)
    {
        if(line[i].type==0)
        {
            inner++;
        }else if(line[i].type==2)
        {
            inner--;
        }else if(line[i].type==1)
        {
            if(inner==0)ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
