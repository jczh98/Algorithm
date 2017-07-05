#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL aa,bb,cc,dd;
LL Gcd(LL a,LL b)
{return b==0?a:Gcd(b,a%b);}
void ExGcd(LL a,LL b,LL &d,LL& x,LL& y){
    if(!b){
        d=a;
        x=1;
        y=0;
    }
    else{
        ExGcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
int main()
{
    cin>>aa>>bb>>cc>>dd;
    LL a=aa,b=-cc,c=dd-bb,x,y,g,t;
    t=Gcd(a,b);
    if(c%t!=0){printf("-1\n");return 0;}
    for(int i=0;i<=10000;i++)
        for(int j=0;j<=10000;j++)
        {
            if(bb+aa*i==dd+cc*j)
            {
                cout<<bb+aa*i<<endl;
                return 0;
            }
        }
    /*if(bb==dd){cout<<bb<<endl;return 0;}
    LL a=aa,b=-cc,c=dd-bb,x,y,g,t;
    t=Gcd(a,b);
    if(c%t!=0){printf("-1\n");return 0;}
    a/=t;b/=t;c/=t;
    ExGcd(a,b,g,x,y);
    x=((c*x)%b+b)%b;
    if(!x)x+=b;
    cout<<bb+x*aa<<endl;*/
    return 0;
}
