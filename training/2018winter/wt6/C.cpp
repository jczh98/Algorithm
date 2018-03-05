#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b;
int main() {
    cin>>a>>b;
    if(__gcd(a,b)!=1||(a==1&&b==1)) printf("infinity infinity\n");
    else {
        cout<<(a-1)*(b-1)/2<<" "<<a*b-a-b<<endl;
    }
    return 0;
}