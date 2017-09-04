#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
int t;
ULL rator,nator,up,down,n,m;
void Simplify(ULL &up,ULL &down)
{
    ULL g=__gcd(up,down);
    up/=g;down/=g;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>n>>m;
        rator=0;nator=0;
        for(int i=1;;i++)
        {
            if(2*(i-1)>=n+m)break;
            up=1;down=1;
            for(int j=0;j<2*(i-1);j++)
            {
                up*=m-j;
                down*=n+m-j;
                Simplify(up,down);
            }
            up*=n;down*=n+m-2*(i-1);
            Simplify(up,down);
            if(nator==0&&rator==0) rator=up,nator=down;
            else rator=rator*down+nator*up,nator=nator*down;
            Simplify(rator,nator);
        }
        cout<<fixed;
        cout<<rator<<"/"<<nator<<endl;
    }
    return 0;
}
