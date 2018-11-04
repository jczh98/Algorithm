#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main() {
    for(ll i = 1; i <= 10000; ++i) {
        for(ll j = i * i + 1; j <= i * i + 2 * i; ++j) {
            ll k = i * i * i * i;
            if((k % j) == 0) {
                printf("%lld %lld\n", i, j); break;
            }
        }
    }
}