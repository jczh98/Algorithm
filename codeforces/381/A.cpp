#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
typedef long long LL;
using namespace std;

LL n,a,b,c;

int main()
{
    cin>>n>>a>>b>>c;
    if(n%4==0){printf("0\n");return 0;}
    n%=4;n=4-n;
    if(n==1)cout<<min(a,min(b+c,3*c))<<endl;
    else if(n==2)cout<<min(a*2,min(b,c*2))<<endl;
    else if(n==3)cout<<min(a*3,min(a+b,c))<<endl;
    return 0;
}
