#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, aa, bb, cc;
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        cin >> aa >> bb >> cc;
        ll up = (aa*(-b+c)+bb*(a-c)+cc*(-a+b));
        ll down = aa+bb+cc;
        ll g = __gcd(abs(up), down);
        up /= g; down /= g;
        if(down == 1) {
            printf("%lld\n", up);
        }else {
            printf("%lld/%lld\n", up, down);
        }        
    }
    return 0;
}