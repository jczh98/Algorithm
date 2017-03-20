#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
LL n;
int main()
{
    cin>>n;
    cout<<((1LL<<(n+1))-2)<<endl;
    return 0;
}
