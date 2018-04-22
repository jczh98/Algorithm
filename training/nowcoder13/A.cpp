#include <bits/stdc++.h>
using namespace std;
string s;
int c1, c2;
int main() {
    cin >> s;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '4') c1++;
        if(s[i] == '7') c2++;
    }
    if(!c1 && !c2) {
        cout << -1 << endl;
    }else if(c1 && !c2) {
        cout << 4 << endl;
    }else if(!c1 && c2) {
        cout << 7 << endl;
    }else {
        if(c1 >= c2) cout << 4 << endl; else cout << 7 << endl;
    }
    return 0;
}