#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
LL n;
string name[]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
LL qpow(LL a,LL b)
{
    LL res=1;
    while(b)
    {
        if(b&1)res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int main()
{
    cin>>n;
    if(n<=5)cout<<name[n-1]<<endl;
    else for(int i=0;i<=32;i++)
    {
        int t1=(qpow(2,i+1)-1)*5,t2=(qpow(2,i+2)-1)*5;
        if(t1<n&&n<=t2)
        {
            int t=n-t1;
            for(int j=0;j<5;j++)
            {
                if(qpow(2,i+1)*j<t&&t<=qpow(2,i+1)*(j+1))
                {
                    cout<<name[j]<<endl;
                    break;
                }
            }
            break;
        }
    }
    return 0;
}
