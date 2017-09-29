#include <bits/stdc++.h>
using namespace std;
int xp, yp, xv, yv, flag = 0;
int main() {
    cin >> xp >> yp >> xv >> yv;
    if(xp <= xv && yp <= yv) flag = 1;
    else if(xp > xv && yp > yv) flag = 0;
    else {
        if(xp + yp <= max(xv, yv)) flag = 1;
        else flag = 0;
    }
    if(flag) cout << "Polycarp" << endl;
    else cout << "Vasiliy" << endl;
    return 0;
}
