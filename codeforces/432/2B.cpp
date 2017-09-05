#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL ax, ay, bx, by, cx, cy;
LL dis(LL x_1, LL y_1, LL x_2, LL y_2){
    return (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);
}
int main() {
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if((ay - by) * (cx - bx) == (cy - by) * (ax - bx)) {
        cout << "No" << endl;
    }else {
        LL d1 = dis(ax, ay, bx, by);
        LL d3 = dis(bx, by, cx, cy);
        if(d1 == d3) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }
    return 0;
}
