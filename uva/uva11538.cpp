#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ULL;
ULL n,m;
int main()
{
    while(true)
    {
        cin>>n>>m;
        if((!n)&&(!m))break;
        if(n>m)swap(n,m);
        cout<<n*m*(m-1)+m*n*(n-1)+2*n*(n-1)*(3*m-n-1)/3<<endl;
    }
    return 0;
}
