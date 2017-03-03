#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
ULL n,f[1000100];
int main()
{
    f[3]=0;
    for(ULL i=4;i<=1000000;i++)f[i]=f[i-1]+((i-1)*(i-2)/2-(i-1)/2)/2;
    while(cin>>n)
    {
        if(n<3)break;
        cout<<f[n]<<endl;
    }
    return 0;
}
