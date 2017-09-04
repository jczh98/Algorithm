#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{double p,x,ans; int N;
 cin>>p>>N;
 if(N==0)cout<<1;
 else
 {
        x=4*p-3*p*p;
        x=sqrt(x);
 //       cout<<x<<endl;
        x-=p;
 //       cout<<x<<endl;
        x/=2*p;
 //       cout<<x<<endl;
 ans=x;
 while(--N)
    ans*=x;
 cout<<setprecision(8)<<fixed<<ans;
 }
    return 0;
}
