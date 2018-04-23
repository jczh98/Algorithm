#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL p, y;
bool check(LL x) {
    for(int i = 2; i * i <= x && i <= p; ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int main() {
    cin >> p >> y; int flag = 0;
    for(int i = y; i >= p + 1; --i) {
        if(check(i)) {
            cout << i << endl; flag = 1; break;
        }
    }
    if(!flag) cout << -1 << endl;
    return 0;
}