#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
LL n;
int main()
{
    cin>>n;
    cout<<n/3*2+(n%3==0?0:1)<<endl;
    return 0;
}
