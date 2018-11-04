#include <bits/stdc++.h>
using namespace std;
int a, b, c;
int main() {
    while(cin >> a >> b >> c) {
        if(a == 1 && b == 1 && c == 1) {
            cout << "No" << endl;
            continue;
        }
        if(c & 1) {
            if((a * b) & 1) {
                cout << "No" << endl;
            }else {
                cout << "Yes" << endl;
            }
        }else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}