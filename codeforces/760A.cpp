#include <cstdio>
#include <cmath>
int m,d,days,ans=1;
int main()
{
    scanf("%d%d",&m,&d);
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)days=31;
    else if(m==4||m==6||m==9||m==11)days=30;
    else days=28;
    days-=7-d+1;
    ans+=days/7+(days%7==0?0:1);
    printf("%d\n",ans);
    return 0;
}
