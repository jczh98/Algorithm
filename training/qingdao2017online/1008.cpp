#include <bits/stdc++.h>
using namespace std;
int t;
map<string, int> mp;
string a, b;
int main() {
    cin >> t;
    mp["rat"] = 1;
    mp["ox"] = 2;
    mp["tiger"] = 3;
    mp["rabbit"] = 4;
    mp["dragon"] = 5;
    mp["snake"] = 6;
    mp["horse"] = 7;
    mp["sheep"] = 8;
    mp["monkey"] = 9;
    mp["rooster"] = 10;
    mp["dog"] = 11;
    mp["pig"] = 12;
    while(t--) {
        cin >> a >> b;
        if(a != b) {
            if(mp[a] < mp[b]) {
                cout << mp[b] - mp[a] << endl;
            }else {
                cout << 12 - mp[a] + mp[b] << endl;
            }
        }else {
            cout << 12 << endl;
        }
    }
    return 0;
}

